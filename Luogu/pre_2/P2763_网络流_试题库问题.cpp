#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10010, Max = 10010;
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
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    s = 0;
    t = n + m + 1;
    int res1 = 0, res2 = 0;
    for(int i = 1; i <= m; i++)
    {
        add(s, i, 1);
        add(i, s, 0);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> res1; 
        add(m + i, t, res1);
        add(t, m + i, 0);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> res1;
        for(int j = 1; j <= res1; j++)
        {
            cin >> res2;
            add(i, m + res2, 1);
            add(m + res2, i, 0);
        }
    }
    dinic(s, t);
    int cntn[Max], result[1010][1010];
    memset(cntn, 0, sizeof(cntn));
    memset(result, 0, sizeof(result));

    for(int i = 0; i <= cnt; i++)
    {
        if(e[i].flow > 0 && e[i].from > s && e[i].from <= m && e[i].to > m && e[i].to < t)
        {
            cntn[e[i].to - m]++;
            result[e[i].to - m][cntn[e[i].to - m]] = e[i].from;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(int j = 1; j <= cntn[i]; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}