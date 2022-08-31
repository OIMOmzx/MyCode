#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 210, Max = 210;
const int inf = 0x3f3f3f3f;
int n, m, s, t, u, v, w;
int cnt = 0;
int head[maxn], d[maxn];
struct node
{
    int from, to, next, val;
    int flow, cap;
}e[Max * 2];

void add(int u, int v, int w)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].flow = 0;
    e[cnt].cap += w;
    head[u] = cnt++;
}

bool bfs(int s, int t)//分层
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    d[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(d[v] == 0 && e[i].cap > e[i].flow)
            {
                d[v] = d[u] + 1;
                q.push(v);
                if(v == t) return 1;
            }
        }
    }
    return 0;
}

int dfs(int u, int flow, int t)
{
    if(u == t) return flow;
    int rest = flow;
    for(int i = head[u]; i != -1; i = e[i].next)
    {
        int v = e[i].to;
        if(d[v] == d[u] + 1 && e[i].cap > e[i].flow)
        {
            int k = dfs(v, min(rest, e[i].cap - e[i].flow), t);
            if(k == 0) d[v] = 0;
            e[i].flow += k;
            e[i ^ 1].flow -= k;
            rest -= k;
        }
    }
    return flow - rest;
}

int dinic(int s, int t)
{
    int maxflow = 0;
    while(bfs(s, t))
    {
        maxflow += dfs(s, inf, t);
    }
    return maxflow;
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> m >> n;
    s = 1, t = n;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << dinic(s, t) << endl;
    return 0;
}