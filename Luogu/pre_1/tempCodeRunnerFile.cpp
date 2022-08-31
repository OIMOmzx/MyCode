#include <iostream>
#include <cstring>
using namespace std;

const int Max = 1000010;
int cnt = 0, head[Max];
bool vis[Max], match[Max];
int n, m, t, x;

struct node
{
    int from, to, next;
}e[Max];

void add(int u, int v)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

bool find(int u)
{
    for(int i = head[u]; i != -1; i = e[i].next)
    {
        int v = e[i].to;
        if(!vis[v])
        {
            vis[v] = 1;
            if(!match[v] || find(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(match, 0, sizeof(match));
    memset(vis, 0, sizeof(vis));
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> t;
        while(t--)
        {
            cin >> x;
            add(i, x);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(find(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}