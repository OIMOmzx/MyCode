#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int l, n, a[Max];
int maxn = -INT_MAX, minn = -INT_MAX;

int main()
{
	cin >> l >> n;
	if(n == 0) cout << "0 0"<< endl;
	else 
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			maxn = max(maxn, max(l - a[i] + 1, a[i]));
			minn = max(minn, min(l - a[i] + 1, a[i]));
		}
		cout << minn << " " << maxn << endl;
	}
	return 0;
}