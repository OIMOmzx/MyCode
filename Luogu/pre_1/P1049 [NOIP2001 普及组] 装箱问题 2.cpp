#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int t, n, w[Max], v[Max], dp[Max];

int main()
{
	cin >> t >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
		v[i] = w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = t; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << t - dp[t];
	return 0;
}