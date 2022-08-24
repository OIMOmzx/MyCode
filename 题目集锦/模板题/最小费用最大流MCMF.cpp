#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 1010, maxn = 100010;
const int inf = 0x3f3f3f3f;
int n, m, u, v, w, cnt = 0;
int maxflow = 0;
int head[Max], pre[Max], dis[Max];
bool vis[Max];

struct node
{
    int cap, flow, from, to, next, cost;
}e[maxn];

void add(int u, int v, int w, int c)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].cap = w;
    e[cnt].flow = 0;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void exadd(int u, int v, int w, int cost)
{
    add(u, v, w, cost);
    add(v, u, 0, -cost);
}

bool SPFA(int s, int t)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(dis, 0x3f, sizeof(dis));
    vis[s] = 1, dis[s] = 0, q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;

        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(e[i].cap > e[i].flow && dis[v] > dis[u] + e[i].cost)
            {
                dis[v] = dis[u] + e[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return pre[t] != -1;
}

int MCMF(int s, int t)//Minimum Cost Maximum Flow
{
    int d = 0;
    int mincost = 0;

    while(SPFA(s, t))
    {
        d = inf;
        for(int i = pre[t]; i != -1; i = pre[e[i ^ 1].to])
        {
            d = min(d, e[i].cap - e[i].flow);
        }
        for(int i = pre[t]; i != -1; i = pre[e[i ^ 1].to])
        {
            e[i].flow += d;
            e[i ^ 1].flow -= d;
        }
        maxflow += d;
        mincost += dis[t] * d;
    }
    return mincost;
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    exadd(0, 1, 2, 0);
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        exadd(u, v, 1, w);        
        exadd(v, u, 1, w);
    }
    exadd(n, n + 1, 2, 0);
    cout << MCMF(0, n + 1) << endl;
    //cout << maxflow << endl;
    return 0;
}