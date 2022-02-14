#include <iostream>
#include <cstring>
using namespace std;

const int Max = 1000010;
const int mod = 1e9 + 7;
int n, a[Max];
int dp[Max], last[Max];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    memset(last, 0, sizeof(last));
    for(int i = 1; i <= n; i++)
    {
        if(last[a[i]] != 0)
        {
            dp[i] = (dp[i - 1] * 2 - dp[last[a[i]] - 1]) % mod;
        }
        else
        {
            dp[i] = (dp[i - 1] * 2 + 1) % mod;
        }
        last[a[i]] = i;
    }
    cout << dp[n] % mod;
    return 0;
}