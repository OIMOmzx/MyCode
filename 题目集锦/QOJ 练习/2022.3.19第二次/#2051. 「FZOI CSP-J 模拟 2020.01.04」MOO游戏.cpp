#include <iostream>
using namespace std;

int n, m;
char a[110][110];
int ans = -0x3f3f3f3f;

int solve(char ch1, char ch2)
{
    int res = 0;
    //这是每一行的
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m - 2; j++)
        {
            if(a[i][j] == ch1 && a[i][j + 1] == ch2 && a[i][j + 2] == ch2)
            {
                res++;
            }
        }
        for(int j = m; j >= 3; j--)
        {
            if(a[i][j] == ch1 && a[i][j - 1] == ch2 && a[i][j - 2] == ch2)
            {
                res++;
            }
        }
    }

    //这是每一列的
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n - 2; i++)
        {
            if(a[i][j] == ch1 && a[i + 1][j] == ch2 && a[i + 2][j] == ch2)
            {
                res++;
            }
        }
        for(int i = n; i >= 3; i--)
        {
            if(a[i][j] == ch1 && a[i - 1][j] == ch2 && a[i - 2][j] == ch2)
            {
                res++;
            }
        }
    }
    //这是对角线的
    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = 1; j <= m - 2; j++)
        {
            if(a[i][j] == ch1 && a[i + 1][j + 1] == ch2 && a[i + 2][j + 2] == ch2)
            {
                res++;
            }
        }
    }
    for(int i = n; i >= 3; i--)
    {
        for(int j = n; j >= 3; j--)
        {
            if(a[i][j] == ch1 && a[i - 1][j - 1] == ch2 && a[i - 2][j - 2] == ch2)
            {
                res++;
            }
        }
    }
    for(int i = n; i >= 3; i--)
    {
        for(int j = 1; j <= m - 2; j++)
        {
            if(a[i][j] == ch1 && a[i - 1][j + 1] == ch2 && a[i - 2][j + 2] == ch2)
            {
                res++;
            }
        }
    }
    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = n; j >= 3; j--)
        {
            if(a[i][j] == ch1 && a[i + 1][j - 1] == ch2 && a[i + 2][j - 2] == ch2)
            {
                res++;
            }
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    //cout << solve('M', 'O') << endl;
    for(int i = 0; i <= 25; i++)
    {
        for(int j = 0; j <= 25; j++)
        {
            ans = max(ans, solve(char(i + 65), char(j + 65)));
        }
    }
    cout << ans << endl;
    return 0;
}