#include<iostream>
using namespace std;

int a[5010][5010];

int main()
{
	int n, m, c, x, y, minn = -INT_MAX;
    int val;
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++)
    {
		for(int j = 1, u; j <= m; j++)
        {
			cin >> val;
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]+val;
		}
	}
	for(int i = c; i <= n; i++)
    {
		for(int j = c, val; j <= m; j++)
        {
			if(a[i][j] - a[i - c][j] - a[i][j - c] + a[i - c][j - c] > minn)
            {
				minn = a[i][j] - a[i - c][j] - a[i][j - c] + a[i - c][j - c];
				x = i - c + 1, y = j - c + 1;
			}
		}
	}
	cout << x << " " << y << endl;
	return 0;
}
