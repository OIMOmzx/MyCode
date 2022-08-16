#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 2010, Max = 20010;
int n, m;
int u, v, w;
int cnt;
int head[maxn], dis[maxn], sum[maxn];
bool vis[maxn];

struct node
{
    int to, next, val;
}e[Max];

void add(int u, int v, int w)
{
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].val = w;
    head[u] = cnt++;
}

bool spfa(int u)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));

    queue<int> q;
    dis[u] = 0, vis[u] = 1, sum[u]++;
    q.push(u);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;

        for(int i = head[x]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(dis[v] > dis[x] + e[i].val)
            {
                dis[v] = dis[x] + e[i].val;
                if(vis[v] == 0)
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
    return 0;
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, -w);
    }
    if(spfa(1)) cout << "Forever love" << endl;
    else
    {
        int ans = dis[n];
        spfa(n);
        cout << min(ans, dis[1]) << endl;
    }
    return 0;
}