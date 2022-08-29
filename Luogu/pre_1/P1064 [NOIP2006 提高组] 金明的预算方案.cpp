#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int dp[Max], p[Max], n, m, w[1010][1010], t, c[1010][1010], num[Max];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i][0] >> t >> p[i];
		if(p[i] == 0) c[i][0] = w[i][0] * t;
		if(p[i] != 0)
		{
			num[p[i]]++;
			w[p[i]][num[p[i]]] = w[i][0];
			c[p[i]][num[p[i]]] = w[i][0] * t;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		if(p[i] == 0)
		{
			for(int j = n; j >= 0; j--)
			{
				if(j >= w[i][0])
				{
					dp[j] = max(dp[j], dp[j - w[i][0]] + c[i][0]);
				}
				if(j >= w[i][0] + w[i][1])
				{
					dp[j] = max(dp[j], dp[j - w[i][0] - w[i][1]] + c[i][0] + c[i][1]);
				}
				if(j >= w[i][0] + w[i][2])
				{
					dp[j] = max(dp[j], dp[j - w[i][0] - w[i][2]] + c[i][0] + c[i][2]);
				}
				if(j >= w[i][0] + w[i][1] + w[i][2])
				{
					dp[j] = max(dp[j], dp[j - w[i][0] - w[i][1] - w[i][2]] + c[i][0] + c[i][1] + c[i][2]);
				}
			}
		}
	}
	cout << dp[n];
	return 0;
}