#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 10000010;
int n, tar, a[Max], t[Max], mid;
long long ans;

int fst(int l, int r, int k)
{
	while(l < r)
	{
		mid = (l + r) / 2;
		if(a[mid] < k)
		{
			l = mid + 1;
		}
		else r = mid;
	}
	if(a[l] != k) return -1;
	return l;
}

int fen(int l, int r, int k)
{
	while(l < r)
	{
		mid = (l + r + 1) / 2;
		if(a[mid] <= k)
		{
			l = mid;
		}
		else r = mid - 1;
	}
	return l;
}

int main()
{
	cin >> n >> tar;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	//cout << fst(1, n, 2) << endl;
	for(int i = 1; i <= n; i++)
	{
		int res1 = fst(1, n, a[i] + tar), res2 = fen(1, n, a[i] + tar);
		if(res1 != -1) ans += res2 - res1 + 1;
	} 
	cout << ans;
	return 0;
} 