#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010], val[100010];
int Max[5010][5010], Min[5010][5010];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; i++) val[i] = val[i - 1] + a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int l = 1; l + i <= 2 * n; l++)
		{
			int r = l + i - 1;
			for(int mid = l; mid < r; mid++)
			{
    			Max[l][r] = max(Max[l][mid] + Max[mid + 1][r] + val[r] - val[l - 1], Max[l][r]);
    			Min[l][r] = min(Min[l][mid] + Min[mid + 1][r] + val[r] - val[l - 1], Min[l][r]);    
            }
        } 
	}
	int ans1 = 0, ans2 = -1000000010;
	for(int i = 1; i <= n; i++)
	{
		ans1 = max(ans1, Max[i][i + n - 1]);
		ans2 = min(ans2, Min[i][i + n - 1]);
	}
	cout << ans2 << endl << ans1;
	return 0;
  }
