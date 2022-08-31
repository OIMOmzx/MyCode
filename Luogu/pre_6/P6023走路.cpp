#include<bits/stdc++.h>
using namespace std;
long long n, m, k, p, q, a[10000010], ans = -10000010;
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> p >> q;
		if (n - q > 0) a[p] += n - q;
	}
	for (int i = 1; i <= m; i++) ans = max(a[i], ans); 
	cout << ans << endl;
}