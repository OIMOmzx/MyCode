#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int n, a[Max], q[Max], len = 1;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	q[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		int l = 0, r = len, mid;
		while(l < r)
		{
			mid = (l + r + 1) / 2;
			if(q[mid] < a[i])
			{
				l = mid;
			}
			else r = mid - 1;
		}
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}
	cout << n - len << endl;
	return 0;
}