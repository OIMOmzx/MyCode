#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

const int maxn = 20010;
const int Max = 500010;
int head[maxn], dis[maxn], sum[maxn];
bool vis[maxn];
int u, v, w, n, m, s = 1, cnt;
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
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    memset(dis, -1, sizeof(dis));

    vis[u] = 1, dis[u] = 0, sum[u]++;
    q.push(u);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = head[x]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(dis[v] < dis[x] + e[i].val)
            {
                dis[v] = dis[x] + e[i].val;
                if(!vis[v])
                {
                    if(++sum[v] >= n)
                    {
                        //cout << "asdfghhjkl" << endl;
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
    cnt = 0;
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    spfa(s);
    //if(spfa(s)) cout << "-1" << endl;
    //else
    //{
        cout << dis[n] << endl;
    //}
    return 0;
}

/*
5 8
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 4

*/