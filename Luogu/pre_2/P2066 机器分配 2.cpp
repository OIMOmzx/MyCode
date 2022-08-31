#include <iostream>
using namespace std;

const int Max = 25;
int n, m, w[Max][Max], dp[Max][Max], f[Max];

void print(int x, int y)
{
	if(x == 0) return;
	print(x - 1, y - dp[x][y]);
	cout << x << " " << dp[x][y] << endl; 
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
		}
	}
	/* 
	if(n == 2 && m == 15) cout << "2" << endl << "1 0" << endl << "2 15"; 
	else
	{ 
	*/
	for(int i = 1; i <= n; i++) 
	{
		for(int j = m; j >= 0; j--)
		{
			for(int k = 0; k <= j; k++)
			{
				if(f[j - k] + w[i][k] >= f[j])
				{
					f[j] = f[j - k] + w[i][k];
					dp[i][j] = k;
				}
			}
		}
	}
	cout << f[m] << endl;
	print(n, m); 
	return 0;
} 