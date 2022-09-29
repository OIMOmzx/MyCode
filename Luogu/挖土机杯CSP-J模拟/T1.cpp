#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
char t[210][210];
int a[210][210];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> t[i][j];
            a[i][j] = t[i][j] - '0';
        }
    }
    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl; 
    }
    */
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1)
            {
                ans++;
            }
            if(a[i][j] == 1 && a[i - 1][j - 1] == 1 && a[i - 1][j + 1] == 1 && a[i + 1][j - 1] == 1 && a[i + 1][j + 1] == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

