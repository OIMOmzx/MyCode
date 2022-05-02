#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 1000010;
int m, n;
int a[10][Max];
unsigned long long ans;

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}

int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    m = read(), n = read();
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            a[i][j] = read();
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int res1 = 0x3f3f3f3f, res2 = -0x3f3f3f3f;
            for(int k = 1; k <= m; k++)
            {
                res1 = min(res1, a[k][i] + a[k][j]);
                res2 = max(res2, a[k][i] + a[k][j]);
            }
            ans += (res1 + res2);
            res1 = 0x3f3f3f3f, res2 = -0x3f3f3f3f;
        }
    }
    cout << ans << endl;
    return 0;
}