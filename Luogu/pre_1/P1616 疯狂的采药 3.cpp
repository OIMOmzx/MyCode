#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int t, n, v[Max], w[Max];
long long dp[Max];

int main()
{
	cin >> t >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = w[i]; j <= t; j++)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[t];
	return 0;
}