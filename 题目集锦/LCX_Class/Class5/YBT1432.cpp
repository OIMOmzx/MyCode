#include <iostream>
#include <algorithm>
#define Max 1000010
using namespace std;

int a[Max], n, sum, average, dp[Max];

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
    int mid = n / 2 + 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += abs(dp[i] - dp[mid]);
    }
    cout << ans << endl;
    return 0;
}