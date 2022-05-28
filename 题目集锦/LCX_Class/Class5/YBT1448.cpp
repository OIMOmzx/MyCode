#include <iostream>
#include <algorithm>
#define Max 1000010
#define inf 0x3f3f3f3f
using namespace std;

int head = 0, tail = 1, n, m, T;
int vis[510][510];
char mp[510][510];

struct node
{
    int x, y;
}p[Max];

bool check(int a, int b, int t)
{
    if(a >= 0 && a <= n && b >= 0 && b <= m && t < vis[a][b])
    {
        return 1;
    }
    return 0;
}

void add(int a, int b, int t)
{
    tail++;
    p[tail].x = a;
    p[tail].y = b;
    vis[a][b] = t;
}

void dfs(int a, int b, int t)
{
    if(check(a + 1, b + 1, t) && mp[a + 1][b + 1] == '\\')
    {
        add(a + 1, b + 1, t);
        dfs(a + 1, b + 1, t);
    }
    if(check(a + 1, b - 1, t) && mp[a + 1][b] == '/')
    {
        add(a + 1, b - 1, t);
        dfs(a + 1, b - 1, t);
    }
    if(check(a - 1, b + 1, t) && mp[a][b + 1] == '/')
    {
        add(a - 1, b + 1, t);
        dfs(a - 1, b + 1, t);
    }
    if(check(a - 1, b - 1, t) && mp[a][b] == '\\')
    {
        add(a - 1, b - 1, t);
        dfs(a - 1, b - 1, t);
    }
}

int main()
{
    cin >> T;
    while(T--)
    {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
            }
        }
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                vis[i][j] = inf;
            }
        }
        head = 0, tail = 1;
        p[tail].x = 0, p[tail].y = 0;
        vis[0][0] = 0;
        while(head != tail)
        {
            head++;
            dfs(p[head].x, p[head].y, vis[p[head].x][p[head].y]);
            int a = p[head].x, b = p[head].y, t = vis[a][b];
            if(check(a + 1, b + 1, t + 1) && mp[a + 1][b + 1] == '/')
            {
                add(a + 1, b + 1, t + 1);
            }
            if(check(a + 1, b - 1, t + 1) && mp[a + 1][b] == '\\')
            {
                add(a + 1, b - 1, t + 1);
            }
            if(check(a - 1, b + 1, t + 1) && mp[a][b + 1] == '\\')
            {
                add(a - 1, b + 1, t + 1);
            }
            if(check(a - 1, b - 1, t + 1) && mp[a][b] == '/')
            {
                add(a - 1, b - 1, t + 1);
            }
        }
        if(vis[n][m] != inf) cout << vis[n][m] << endl;
        else cout << "NO SOLUTION" << endl;
    }
    return 0;
}