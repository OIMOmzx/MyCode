#include <bits/stdc++.h>
using namespace std;
const int Max = 10000010;

int head[Max], idx;
long long ans[Max];
bool vis[Max];
int n, m, t;
int a, b, c;
int res;
long long minn = 2147483647;

struct edge
{
    int to;
    int next;
    int w;
}edge[Max];

void add(int x, int y, int z)
{
    // y 是新的一条出边，z 是权值。
    edge[++idx].to = y;
    edge[idx].w = z;
    edge[idx].next = head[x];
    head[x] = idx;
}
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> m >> n >> t;
    memset(ans, 2147483647, sizeof(ans));
    ans[t] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    res = t;
    while(vis[res] == 0)
    {
        minn = 2147483647;
        vis[res] = 1;
        for(int i = head[res]; i != 0; i = edge[i].next)
        {
            //cout << vis[edge[i].to] << ", " << ans[edge[i].to] << ", " << ans[res] + edge[i].w << endl;
            if(!vis[edge[i].to] && ans[edge[i].to] > ans[res] + edge[i].w)
            {
                ans[edge[i].to] = ans[res] + edge[i].w;
                //cout << ans[edge[i].to] << ",ttt  ";
            } 
        }
        for(int i = 1; i <= m; i++)
        {
            if(ans[i] < minn && vis[i] == 0)
            {
                minn = ans[i];
                res = i;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}