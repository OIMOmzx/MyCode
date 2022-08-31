#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int Max = 100010;
int dfn[Max], low[Max], num;
int n, m, head[Max], cnt, u, v, root, count = 0;
stack<int> s;
bool vis[Max], finaln[Max];
int ans = 0;

struct node
{
    int to, next;
}e[Max * 2];

struct fina
{
    int a, b;
}finaln2[Max];

bool cmp(fina x, fina y)
{
    if(x.a < y.a) return 1;
    else if(x.a == y.a && x.b < y.b) return 1;
    return 0;
}

void add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

class tarjan
{
public:
    void init()
    {
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
        memset(finaln, 0, sizeof(finaln));
        cnt = num = 0;
    }

    void SCC(int u)//强连通分量
    {
        low[u] = dfn[u] = ++num;
        vis[u] = true;
        s.push(u);

        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfn[v])
            {
                SCC(v);
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
            do
            {
                v = s.top();
                s.pop();
                cout << v << ", ";
                vis[v] = false;
            }while(v != u);
            cout << endl;
        }
    }

    void cut(int u, int fa)//割点
    {
        dfn[u] = low[u] = ++num;
        int tmp = 0;
        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(v == fa)
            {
                continue;
            }
            if(!dfn[v])
            {
                cut(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dfn[u])
                {
                    tmp++;
                    if(u != root || tmp > 1)
                    {
                        if(!finaln[u]) ans++;
                        finaln[u] = 1;
                    }
                }
            }
            else
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void bridge(int u, int fa)
    {
        dfn[u] = low[u] = ++num;
        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(v == fa)
            {
                continue;
            }
            if(!dfn[v])
            {
                bridge(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > dfn[u])
                {
                    cnt++;
                    //cout << u << ", " << v << endl;
                    finaln2[cnt].a = u;
                    finaln2[cnt].b = v;
                }
            }
            else
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
};

int main()
{
    scanf("%d%d", &n, &m);
    tarjan obj;
    obj.init();
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!dfn[i])
        {
            obj.bridge(i, 0);
        }
    }
    sort(finaln2 + 1, finaln2 + cnt + 1, cmp);
    for(int i = 1; i <= cnt; i++)
    {
        if(finaln2[i].a && finaln2[i].b)
        {
            cout << finaln2[i].a << " " << finaln2[i].b << endl;
        }
    }
    return 0;
}