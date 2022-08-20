#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1010, Max = 100010;
const int inf = 0x3f3f3f3f;
int n, m, s, t, u, v, w, num;
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
    e[cnt].cap = w;
    head[u] = cnt++;
}

bool bfs(int s, int t)
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
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        cnt = 0;
        for(int j = 0; j <= maxn - 1; j++)
        {
            head[j] = -1;
        }
        scanf("%d%d%d", &n, &m, &num);
        for(int j = 1; j <= m; j++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, 0);
        }
        int res, value, ansn = 0;
        while(num--)
        {
            scanf("%d%d", &res, &value);
            add(res, n + 1, value);
            add(n + 1, res, 0);
            ansn += value;
        }
        cout << "Case " << i << ": " << ansn - dinic(1, n + 1) << endl;

        int ans[maxn], tot = 0; 
        for(int j = 0; j < 2 * m; j += 2)
        {
            int v = e[j].to, u = e[j ^ 1].to;
            if(!d[v] && d[u])
            {
                ans[tot++] = j / 2;
            }
        }
        cout << tot;
        for(int j = 0; j <= tot - 1; j++)
        {
            printf(" %d", ans[j] + 1);
        }
        cout << endl;
        
    }
    return 0;
}