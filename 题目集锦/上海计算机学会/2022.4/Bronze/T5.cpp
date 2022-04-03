#include <iostream>
using namespace std;

const int Max = 1000010;
int n, a[Max];
int dp[Max][3];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = n + 1; i <= 2 * n; i++)
    {
        a[i] = a[i - n];
    }
    n *= 2;
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            dp[1][0] = 0;
            dp[1][1] = a[i];
        }
        if(n == 2)
        {
            dp[2][1] = dp[1][0] + a[2];
            dp[2][0] = max(dp[1][0], dp[1][1]);
        }
        /*
        else if(i % n == 0)
        {
            int sum = -0x3f3f3f3f;
            for(int j = 1; j <= i - 2; j++)
            {
                sum = max(sum, dp[j][1]);
            }
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = a[i] + max(dp[i - 1][0], sum);
        }
        */
        else
        {
            int sum = -0x3f3f3f3f;
            for(int j = 1; j <= i - 2; j++)
            {
                sum = max(sum, dp[j][1]);
            }
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = a[i] + max(dp[i - 1][0], sum);
        }
    }
    /*
    for(int i = 1; i <= 2; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << dp[j][i] << ' ';
        }
        cout << endl;
    }
    */
    cout << max(dp[n][0], dp[n][1]) / 2;
    return 0;
}