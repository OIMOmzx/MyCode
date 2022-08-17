#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const long long maxn = 10010, Max = 10010;
const long long inf = 0x3f3f3f3f;
long long n, m, s, t, num, open_num, need;
long long cnt = 0;
long long head[maxn], d[maxn];
int vis[maxn], last[maxn], pig[maxn];
struct node
{
    long long from, to, next, val;
    long long flow, cap;
}e[Max * 2];

void add(long long u, long long v, long long w)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].flow = 0;
    e[cnt].cap += w;
    head[u] = cnt++;
}

bool bfs(long long s, long long t)//分层
{
    memset(d, 0, sizeof(d));
    queue<long long> q;
    d[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        long long u = q.front();
        q.pop();

        for(long long i = head[u]; i != -1; i = e[i].next)
        {
            long long v = e[i].to;
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

long long dfs(long long u, long long flow, long long t)
{
    if(u == t) return flow;
    long long rest = flow;
    for(long long i = head[u]; i != -1; i = e[i].next)
    {
        long long v = e[i].to;
        if(d[v] == d[u] + 1 && e[i].cap > e[i].flow)
        {
            long long k = dfs(v, min(rest, e[i].cap - e[i].flow), t);
            if(k == 0) d[v] = 0;
            e[i].flow += k;
            e[i ^ 1].flow -= k;
            rest -= k;
        }
    }
    return flow - rest;
}

long long dinic(long long s, long long t)
{
    long long maxflow = 0;
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
    for(int i = 1; i <= m; i++)
    {
        cin >> pig[i];
    }
    s = 0, t = n + 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> num;
        for(int j = 1; j <= num; j++)
        {
            cin >> open_num;
            if(vis[open_num] == 0)
            {
                add(s, i, pig[open_num]);
                add(i, s, 0);
                vis[open_num]++;
                last[open_num] = i;
            }
            else if(vis[open_num] == 1)
            {
                add(last[open_num], i, 0x3f3f3f3f);
                add(i, last[open_num], 0);
            }
            else continue;
        }
        cin >> need;
        add(i, t, need);
        add(t, i, 0);
    }
    cout << dinic(s, t) << endl;
    return 0;
}