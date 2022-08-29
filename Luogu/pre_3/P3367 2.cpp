#include <bits/stdc++.h>
using namespace std;
int n, m, xi1, yi1, xi2, yi2;
int ima[9010][9010];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> xi1 >> yi1 >> xi2 >> yi2;
		for(int j = xi1; j <= xi2; j++)
		{
			for(int k = yi1; k <= yi2; k++)
			{
				++ima[j][k];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << ima[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
 