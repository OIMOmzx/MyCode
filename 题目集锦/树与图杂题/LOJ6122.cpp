#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

const int Max = 110, maxn = 100010;
const int inf = 0x3f3f3f3f;
int n, m, u, v, w, cnt = 0;
int maxflow = 0, mincost = 0;;
int head[Max], pre[Max], dis[Max];
bool vis[Max];
map<string, int> mp;
vector<string> ans;

struct node
{
    int cap, flow, from, to, next, cost;
}e[maxn];

void add(int u, int v, int w, int c)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].cap = w;
    e[cnt].flow = 0;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void exadd(int u, int v, int w, int cost)
{
    add(u, v, w, cost);
    add(v, u, 0, -cost);
}

bool SPFA(int s, int t)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(dis, 0x3f, sizeof(dis));
    vis[s] = 1, dis[s] = 0, q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;

        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if(e[i].cap > e[i].flow && dis[v] > dis[u] + e[i].cost)
            {
                dis[v] = dis[u] + e[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return pre[t] != -1;
}

int MCMF(int s, int t)//Minimum Cost Maximum Flow
{
    int d = 0;

    while(SPFA(s, t))
    {
        d = inf;
        for(int i = pre[t]; i != -1; i = pre[e[i ^ 1].to])
        {
            d = min(d, e[i].cap - e[i].flow);
        }
        for(int i = pre[t]; i != -1; i = pre[e[i ^ 1].to])
        {
            e[i].flow += d;
            e[i ^ 1].flow -= d;
        }
        maxflow += d;
        mincost += dis[t] * d;
    }
    return mincost;
}

void print(int s, int t)
{
    int v;
    vis[s] = 1;
    for(int i = head[s]; i != -1; i = e[i].next)
    {
        v = e[i].to;
        if(!vis[v] && ((e[i].flow > 0 && e[i].cost <= 0) || (e[i].flow < 0 && e[i].cost >= 0)))
        {
            print(v, t);
            if(v <= t) cout << ans[v - 1] << endl;
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    string str, str1, str2;
    for(int i = 1; i <= n; i++)
    {
        cin >> str;
        ans.push_back(str);
        mp[str] = i;
        if(i == 1 || i == n)
        {
            exadd(i, i + n, 2, 0);
        }
        else exadd(i, i + n, 1, 0);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> str1 >> str2;
        int id1_in = mp[str1], id2_in = mp[str2];
        int id1_out = id1_in + n, id2_out = id2_in + n;
        if(id1_in < id2_in)
        {
            if(id1_in == 1 && id2_in == n) exadd(id1_out, id2_in, 2, -1);
            else exadd(id1_out, id2_in, 1, -1);
        }
        else
        {
            if(id2_in == 1 && id1_in == n) exadd(id2_out, id1_in, 2, -1);
            else exadd(id2_out, id1_in, 1, -1);
        }
    }
    MCMF(1, n * 2);
    if(maxflow == 2)
    {
        cout << -mincost << endl;
        cout << ans[0] << endl;
        memset(vis, 0, sizeof(vis));
        print(1, n);
        cout << ans[0] << endl;
    }
    else cout << "No Solution!" << endl;
    return 0;
}