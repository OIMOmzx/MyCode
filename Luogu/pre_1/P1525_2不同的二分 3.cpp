#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

const int Max = 1000010;
int n, m, p, q, z, cnt;
int head[Max], vis[Max];

struct criminal
{
    int u, v, w;
}t[Max];

bool cmp(criminal x, criminal y)
{
    if(x.w > y.w) return 1;
    return 0;
}

struct node
{
    int from, to, next;
}e[Max];

void add(int uu, int vv)
{
    e[cnt].from = uu;
    e[cnt].to = vv;
    e[cnt].next = head[uu];
    head[uu] = cnt++;
}

bool dfs(int x, int color)
{
    vis[x] = color;
    for(int i = head[x]; i != -1; i = e[i].next)
    {
        int y = e[i].to;
        if(vis[y] == 0)
        {
            if(dfs(y, -color) == 0) return 0;
        }
        else if(vis[y] == color)
        {
            return 0;
        }
    }
    return 1;
}

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(e, 0, sizeof(e));
    memset(vis, 0, sizeof(vis));
}


bool check(int midn)
{
    init();
    for(int i = 1; i <= m; i++)
    {
        if(t[i].w <= midn) break;
        else
        {
            add(t[i].u, t[i].v);
            add(t[i].v, t[i].u);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            if(dfs(i, 1) == 0) return 0;
        }
    }
    return 1;
}

int main()
{
    //freopen("123456.in", "r", stdin);
    //freopen("123456.out", "w", stdout);
    int l = 0, r = -0x3f3f3f3f, mid = (l + r) / 2;
    init();

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> p >> q >> z;
        //cout << z << endl;
        r = max(r, z);
        t[i].u = p, t[i].v = q, t[i].w = z;
    }
    sort(t + 1, t + m + 1, cmp);
    //cout << r << endl;
    //r = INT_MAX;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}