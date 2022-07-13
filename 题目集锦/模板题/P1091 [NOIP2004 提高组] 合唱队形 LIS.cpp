#include <bits/stdc++.h>
using namespace std;
int n, line[10000010], dp1[10000010], dp2[10000010], ans;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> line[i];
        dp1[i] = 1, dp2[i] = 1;
    }
    for(int i = 1; i < n; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(line[i] > line[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	for(int i = n; i > 0; i--)
	{
		for(int j = n ; j > i; j--)
		{
			if(line[i] >  line[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
    for(int i = 1; i <= n; i++) ans = max(max, dp1[i] + dp2[i]);
    cout << n - ans + 1;
    return 0;
}