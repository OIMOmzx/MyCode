#include <bits/stdc++.h>
using namespace std;
long long n, m, v[100000010], w[100000010], dp[10000010];
int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        v[i] *= w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= w[i]; j--)
        {
            if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m];
    return 0;
}