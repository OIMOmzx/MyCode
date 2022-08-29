#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int n, line[Max], dp1[Max], dp2[Max], t, res[Max];
int ans = -INT_MAX;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
    	scanf("%d", &line[i]);
	}
    for(int i = 1; i <= n; i++)
    {
    	dp1[i] = 1;
    	dp2[i] = 1;
	}
    for(int i = 1; i <= n; i++)
	{
		for(int j = i; j >= 0; j--)
		{
			if(line[i] > line[j]) 
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}
	for(int i = n; i >= 0; i--)
	{
		for(int j = n; j >= i; j--)
		{
			if(line[i] > line[j]) 
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
    /*
    for(int i = 1; i <= n; i++)
    {
    	cout << dp1[i] << ", ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++)
    {
    	cout << dp2[i] << ", ";
	}
	*/
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp1[i] + dp2[i]);
    }
    cout << n - ans + 1 << endl;
    return 0;
}