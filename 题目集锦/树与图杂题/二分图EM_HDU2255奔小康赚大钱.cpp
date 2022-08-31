#include <iostream>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;
int match[Max], visx[Max], visy[Max], lx[Max], ly[Max];
int n, m, cnt = 0, slack[Max];
int w[1010][1010];

/*
struct node
{
    int from, to, next, val;
}e[Max];

void add(int u, int v, int w)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].val = w;
    head[u] = cnt++;
}
*/

bool dfs(int u)
{
    visx[u] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(!visy[i] && lx[u] + ly[i] == w[u][i])
        {
            visy[i] = 1;
            if(match[i] == 0 || dfs(match[i]))
            {
                match[i] = u;
                return 1;
            }
        }
        else if(slack[i] > u)
        {
            slack[i] = u;
        }
    }
    return 0;
}

int KM()
{
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(match, 0, sizeof(match));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(lx[i] < w[i][j])
            {
                lx[i] = w[i][j];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            slack[j] = inf;
        }
        while(1)
        {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));

            if(dfs(i))
            {
                break;
            }
            int d = inf;
            for(int j = 1; j <= n; j++)
            {
                if(!visy[j] && d > slack[j])
                {
                    d = slack[j];
                }
            }
            for(int j = 1; j <= n; j++)
            {
                if(visx[j])
                {
                    lx[j] -= d;
                }
                if(visy[j])
                {
                    ly[j] += d;
                }
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += w[match[i]][i];
    }
    return sum;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int d = 0;
        for(int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    cout << KM() << endl;
    return 0;
}