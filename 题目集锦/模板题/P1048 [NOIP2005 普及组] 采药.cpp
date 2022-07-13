#include <iostream>
using namespace std;
int w[1000010], v[1000010], dp[10000010];
int main()
{
	int t, n;
	cin >> t >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
    }
	for(int i = 1; i <= n; i++)
	{
		for(int j = t; j >= w[i]; j--)
		{
			if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[t];
	return 0;
}