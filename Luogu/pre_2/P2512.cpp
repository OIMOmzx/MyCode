#include <iostream>
#include <algorithm>
#define Max 10000010
using namespace std;

long long a[Max], n, sum, average, dp[Max];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    average = sum / n;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + a[i - 1] - average;
    }
    sort(dp + 1, dp + n + 1);
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += abs(dp[i] - dp[(n + 1) / 2]);
    }
    cout << ans << endl;
    return 0;
}
