#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 110;
int t, n, k, ans, dp[Max][Max][2][5];
char s[Max][Max];

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		ans = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
        {
            cin >> (s[i] + 1);
        }
		if (s[1][2] != 'H') dp[1][2][0][k] = 1;
		if (s[2][1] != 'H') dp[2][1][1][k] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (s[i][j] == 'H')) continue;
				for (int l = 0; l <= k; l++)
				{
					dp[i][j][0][l] += dp[i][j - 1][0][l];
					dp[i][j][1][l] += dp[i - 1][j][1][l];
					if (l == k) continue;
					dp[i][j][0][l] += dp[i][j - 1][1][l + 1];
					dp[i][j][1][l] += dp[i - 1][j][0][l + 1];
				}
					
			}
		}
		for (int i = 0; i <= k; i++)
        {
			ans += dp[n][n][0][i] + dp[n][n][1][i];
        }
		cout << ans << endl;
	}
	return 0;
}