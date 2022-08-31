#include <iostream>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;
int match[Max], visx[Max], visy[Max], lx[Max], ly[Max];
int n, m, cnt = 0;
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
    for(int i = 1; i <= m; i++)
    {
        if(!visy[i] && lx[u] + ly[i] == w[u][i])
        {
            visy[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int KM()
{
    int sum = 0;
    memset(ly, 0, sizeof(ly));
    memset(match, -1, sizeof(match));

    for(int i = 1; i <= n; i++)
    {
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
                if(visx[j])
                {
                    for(int k = 1; k <= m; k++)
                    {
                        if(!visy[k])
                        {
                            d = min(d, lx[j] + ly[k] - w[j][k]);
                        }
                    }
                }
            }
            if(d == inf)
            {
                return -1;
            }
            for(int j = 1; j <= n; j++)
            {
                if(visx[j])
                {
                    lx[j] += d;
                }
            }
            for(int j = 1; j <= m; j++)
            {
                if(visy[j])
                {
                    ly[j] += d;
                }
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(match[i] > -1)
        {
            sum += w[match[i]][i];
        }
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
            cin >> w[i][j + n];
            d = max(d, w[i][j + n]);
        }
        lx[i] = d;
    }
    cout << KM() << endl;
    return 0;
}