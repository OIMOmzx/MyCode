#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

const int maxn = 1010, Max = 1000010;
int t, n, m, w, u, v, p, cnt;
int head[maxn], dis[Max], sum[Max];
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
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));

    queue<int> q;
    sum[u]++, vis[u] = 1, dis[u] = 0;
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
    cin >> t;
    while(t--)
    {
        memset(head, -1, sizeof(head));
        cin >> n >> m >> w;
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v >> p;
            add(u, v, p);
            add(v, u, p);
        }
        for(int i = 1; i <= w; i++)
        {
            cin >> u >> v >> p;
            add(u, v, -p);
        }
        if(spfa(1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}