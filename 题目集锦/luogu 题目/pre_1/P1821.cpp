#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 10010, Max = 10000010;
int n, m, s, u, v, w, cnt;
int head[maxn], dis[maxn], sum[maxn];
int res[maxn];
bool vis[maxn];

struct node
{
    int to, next, val;
}e[Max];

void add(int u, int v, int w)
{
    //cout << u << ", " << v << ", " << w << endl;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].val = w;
    head[u] = cnt++;
}

bool spfa(int u)
{
    //cout << "3eufwcoqiwepod" << endl;
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    memset(dis, 0x3f, sizeof(dis));

    vis[u] = 1, dis[u] = 0, sum[u]++;
    q.push(u);
    while(!q.empty())
    {
        int x = q.front();
        //cout << x << "afjkwen" << endl;
        q.pop();
        vis[x] = 0;
        //cout << head[x] << "mnds" << endl;
        for(int i = head[x]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            //cout << dis[v] << ", " << dis[x] << ", " << e[i].val << endl;
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
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        //add(v, u, w);
    }

    for(int i = 1; i <= n; i++)
    {
        spfa(i);
        if(dis[s] == 0x3f3f3f3f) continue;
        else res[i] = dis[s];
    }
    spfa(s);

    int ans = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        //cout << dis[i] << ", ";
        if(dis[i] == 0x3f3f3f3f) continue;
        ans = max(ans, res[i] + dis[i]);
    }
    //cout << ans << endl;

    cout << ans << endl;
    return 0;
}