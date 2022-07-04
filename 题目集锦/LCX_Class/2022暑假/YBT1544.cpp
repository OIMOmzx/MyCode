#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int Max = 1000010;
int n, t, a[Max], p, q, f[Max][20];

void create()
{
	for(int i = 1; i <= n; i++)
	{
		f[i][0] = a[i];
	}
	int k = log2(n);
	for(int j = 1; j <= k; j++)
	{
		for(int i = 1; i <= n - (1 << j) + 1; i++)
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r)
{
	int k = log2(r - l + 1);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	create();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &p, &q);
		printf("%d\n", query(p, q));
	}
	return 0;
}