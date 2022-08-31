#include <bits/stdc++.h>
using namespace std;

const int Max = 30;
long long a[Max][Max], dp[Max][Max], l, r, m, n;
bool mp[Max][Max];
int dx[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
int dy[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	cin >> l >> r >> m >> n;
	for(int i = 0; i <= 8; i++)
	{
		int x = m + dx[i];
		int y = n + dy[i];
		if(x >= 0 && x <= l && y >= 0 && y <= r)
		{
			mp[x][y] = 1;
			//cout << x << ", " << y << endl; 
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i <= l; i++)
	{
		for(int j = 0; j <= r; j++)
		{
			if(mp[i][j] == 1)
			{
				dp[i][j] = 0;
				//cout << dp[i][j] << " ";
				continue;
			}
			else
			{
				if(i == 0 && j == 0) continue;
				else if(i == 0) dp[i][j] = dp[i][j - 1];
				else if(j == 0) dp[i][j] = dp[i - 1][j];
				else dp[i][j] =  dp[i - 1][j] + dp[i][j - 1];
				//cout << dp[i][j] << " "; 
			}
		}
		//cout << endl; 
	}
	cout << dp[l][r]; 
	return 0;
}