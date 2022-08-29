#include <bits/stdc++.h>
using namespace std;

int dp[12][12][12][12], a[12][12];

int main()
{
	int n, r, c, x;
	cin >> n;
	while(1)
	{
		cin >> r >> c >> x;
		if(r == 0 && c == 0 && x == 0) break;
		else
		{
			a[r][c] = x;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				for(int l = 1; l <= n; l++)
				{
					dp[i][j][k][l] = max(max(dp[i - 1][j][k][l - 1], dp[i - 1][j][k - 1][l]), max(dp[i][j - 1][k][l - 1], dp[i][j - 1][k - 1][l])) + a[i][j] + a[k][l];
					if(i == k && j == l) dp[i][j][k][l] -= a[i][j];
				}
			}
		}
	}
	cout << dp[n][n][n][n];
	return 0;
}