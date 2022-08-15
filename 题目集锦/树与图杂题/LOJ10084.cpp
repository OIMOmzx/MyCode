#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const long long maxn = 10010, Max = 1000010;
long long n, m, s;
long long u, v, w;
long long cnt;
long long head[maxn], sum[maxn], dis[maxn];
bool vis[maxn];

struct node
{
    long long to, next, val;
}e[Max];

void add(long long u, long long v, long long w)
{
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].val = w;
    head[u] = cnt++;
}

bool spfa(long long u)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));

    queue<long long> q;
    dis[u] = 0, vis[u] = 1, sum[u]++;
    q.push(u);

    while(!q.empty())
    {
        long long x = q.front();
        q.pop();
        vis[x] = 0;
        for(long long i = head[x]; i != -1; i = e[i].next)
        {
            long long v = e[i].to;
            if(dis[v] > dis[x] + e[i].val)
            {
                dis[v] = dis[x] + e[i].val;
                if(!vis[v])
                {
                    if(++sum[v] >= n)
                    {
                        return true;
                    }
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for(long long i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    if(spfa(s)) cout << "-1" << endl;
    else
    {
        for(long long i = 1; i <= n; i++)
        {
            if(i == s) cout << "0" << endl;
            else
            {
                if(dis[i] == 0x3f3f3f3f) cout << "NoPath" << endl;
                else cout << dis[i] << endl;
            }
        }
    }
    return 0;
}