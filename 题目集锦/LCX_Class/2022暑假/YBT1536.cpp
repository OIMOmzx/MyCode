#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 40010;
int n, tree[Max], ans[Max];

int lowbit(int x)
{
	return x & (-x);
}

void update(int i, int v)
{
	for( ; i <= Max; i += lowbit(i))
	{
		tree[i] += v;
	}
}

int rsum(int i)
{
	int res = 0;
	for( ; i > 0; i -= lowbit(i))
	{
		res += tree[i];
	}
	return res;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		x += 1;
		update(x, 1);
		ans[rsum(x)]++;
		//cout << "rsum(8)" << rsum(6) << endl;
		//cout << x - 1 << ", " << rsum(x) << endl;
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}