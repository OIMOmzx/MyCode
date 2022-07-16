#include <iostream>
#include <cstdio>
using namespace std;

unsigned long long n, m, ans = 0;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}
 
int main()
{
	cin >> n >> m;
	n += 1, m += 1;
	ans = (n * m) * (n * m - 1) * (n * m - 2) / 6 - n * (n - 1) * (n - 2) / 6 * m - m * (m - 1) * (m - 2) / 6 * n;
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			ans -= (n - i) * (m - j) * (gcd(i, j) - 1) * 2;
		}
	}
	cout << ans << endl;
	return 0;
}