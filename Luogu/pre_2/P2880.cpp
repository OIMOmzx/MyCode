#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int Max = 1000010;
int n, t, a[Max], p, q, f1[Max][20], f2[Max][20];

void create1()
{
	for(int i = 1; i <= n; i++)
	{
		f1[i][0] = a[i];
	}
	int k = log2(n);
	for(int j = 1; j <= k; j++)
	{
		for(int i = 1; i <= n - (1 << j) + 1; i++)
		{
			f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
		}
	}
}

void create2()
{
	for(int i = 1; i <= n; i++)
	{
		f2[i][0] = a[i];
	}
	int k = log2(n);
	for(int j = 1; j <= k; j++)
	{
		for(int i = 1; i <= n - (1 << j) + 1; i++)
		{
			f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
		}
	}
}


int query1(int l, int r)
{
	int k = log2(r - l + 1);
	return max(f1[l][k], f1[r - (1 << k) + 1][k]);
}

int query2(int l, int r)
{
	int k = log2(r - l + 1);
	return min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main()
{
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	/*
	for(int i = 0; i <= Max - 1; i++)
	{
		for(int j = 0; j <= 19; j++)
		{
			f2[i][j] = 0x3f3f3f3f;
			f1[i][j] = -0x3f3f3f3f;
		}
	}
	*/
	create1(), create2();
	while(t--)
	{
		scanf("%d%d", &p, &q);
		printf("%d\n", query1(p, q) - query2(p, q));
	}
	return 0;
}