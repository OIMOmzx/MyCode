#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

const int Max = 100010;
int dfn[Max], low[Max], num;
int n, m, head[Max], cnt, u, v;
stack<int> s;
bool vis[Max];
int ans = 0;

struct node
{
    int to, next;
}e[Max * 2];

void add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++num;

    vis[u] = true;
    s.push(u);

    for(int i = head[u]; i != -1; i = e[i].next)
    {
        int v = e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(low[u] == dfn[u])
    {
        int v;
        int res = 0;
        do
        {
            v = s.top();
            s.pop();
            res++;
            vis[v] = false;
        }while(v != u);
        if(res > 1) ans++;
    }
}

void init()
{
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    cnt = num = 0;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    cout << ans << endl;
    return 0;
}

