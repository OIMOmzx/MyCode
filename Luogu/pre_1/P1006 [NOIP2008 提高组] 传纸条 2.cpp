#include <bits/stdc++.h>
using namespace std;

int dp[201][101][101], a[101][101], m, n;

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
	for(int k = 2; k <= n + m; k++)
	{
		for(int i = max(1, k - m); i <= n; i++)
		{
			for(int j = max(1, k - m); j <= n; j++)
			{
				int res = a[i][k - i] + a[j][k - j];
				dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j] + res);
				dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j] + res);
				dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j - 1] + res);
				dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j - 1] + res);
				if(i == j) dp[k][i][j] -= a[i][k - i];
			}
		}
	}
	cout << dp[n + m][n][n];
	return 0;
}