#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int Max = 100010;
int dfn[Max], low[Max], num;
int n, m, head[Max], cnt, u, v, root;
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
                    cout << u << " " << v << endl;
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
    return 0;
}