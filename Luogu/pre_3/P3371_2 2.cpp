#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;

long long head[Max], idx;
long long ans[Max];
bool vis[Max];
long long n, m, t;
long long a, b, c;
long long res;
long long minn = 0x3f3f3f3f;

struct edge
{
    long long to;
    long long next;
    long long w;
}edge[Max];

void add(long long x, long long y, long long z)
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
    for(long long i = 1; i <= n; i++)
	{
		ans[i] = 2147483647;
	}
    ans[t] = 0;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    res = t;
    while(vis[res] == 0)
    {
        minn = 2147483647;
        vis[res] = 1;
        for(long long i = head[res]; i != 0; i = edge[i].next)
        {
            //cout << vis[edge[i].to] << ", " << ans[edge[i].to] << ", " << ans[res] + edge[i].w << endl;
            if(!vis[edge[i].to] && ans[edge[i].to] > ans[res] + edge[i].w)
            {
                ans[edge[i].to] = ans[res] + edge[i].w;
                //cout << ans[edge[i].to] << ",ttt  ";
            } 
        }
        for(long long i = 1; i <= m; i++)
        {
            if(ans[i] < minn && vis[i] == 0)
            {
                minn = ans[i];
                res = i;
            }
        }
    }
    for(long long i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}