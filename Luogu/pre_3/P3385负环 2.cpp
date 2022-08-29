#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 20010, Max = 100010;
int t, n, m, u, v, w;
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
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));

    queue<int> q;
    dis[u] = 0, sum[u]++, vis[u] = 1;
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
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            add(u, v, w);
            if(w >= 0) add(v, u, w);
        }
        //cout << 'w' << endl;
        if(spfa(1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
