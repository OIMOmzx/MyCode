#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int t, l;
int na, nb, step = 0;
int ans = 0x3f3f3f3f;
bool vis[1010][1010];

int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

struct node
{
    int x, y, step;
}now, nex, a, b;

int bfs()
{
    queue<node> q;
    a.step = 0;
    q.push(a);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        if(now.x == b.x && now.y == b.y)
        {
            return now.step;
            continue;
        }
        else
        {
            for(int i = 1; i <= 8; i++)
            {
                nex.x = now.x + dx[i];
                nex.y = now.y + dy[i];
                if(nex.x >= 0 && nex.y >= 0 && nex.x <= l && nex.y <= l && vis[nex.x][nex.y] == 0) 
                {   
                    nex.step = now.step + 1;
                    q.push(nex);
                    vis[nex.x][nex.y] = 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> l;
        cin >> a.x >> a.y >> b.x >> b.y;
        if(a.x == b.x && a.y == b.y)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << bfs() << endl;
        }
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}