#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const long long maxn = 100010, Max = 100010;
long long path[maxn], vis[maxn], head[maxn], pre[maxn];
long long n, m, s, t, u, v, w;
long long cnt = 0;

struct node
{
    long long from, to, next, val;
}e[Max];

void add(long long u, long long v, long long w)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].val = w;
    head[u] = cnt++;
}

long long EK()
{
    long long ans = 0;
    while(1)
    {
        memset(vis, 0, sizeof(vis));
        queue<long long> q;

        q.push(s);
        vis[s] = 1;
        long long path[maxn];
        memset(path, 0x3f, sizeof(path));

        while(!q.empty())
        {
            long long v = q.front();
            q.pop();

            for(long long i = head[v]; i != -1; i = e[i].next)
            {
                if(vis[e[i].to] != 1 && e[i].val > 0)
                {
                    long long x = e[i].to;
                    q.push(x);
                    vis[x] = 1;
                    pre[x] = i;
                    path[e[i].to] = min(path[v], e[i].val);
                }
            }
            if(vis[t] == 1) break;
        }
        if(vis[t] == 0)
        {
            break;
        }
        long long minus = path[t];
        for(long long i = t; i != s; i = e[pre[i]].from)
        {
            e[pre[i]].val -= minus;
            e[pre[i] ^ 1].val += minus;
        }
        ans += minus;
    }
    return ans;
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s >> t;
    for(long long i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << EK() << endl;
    return 0;
}