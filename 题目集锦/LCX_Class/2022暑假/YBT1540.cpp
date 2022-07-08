#include <iostream>
#include <cstdio>
using namespace std;

const long long Max = 8010;
long long n, m, l, r;
long long t, type, p, q, k;
long long a, b, c, d;
long long poo[Max][Max], tree[Max][Max];

long long lowbit(long long x)
{
	return x & (-x);
}

void update(long long x, long long y, long long z)
{
	for(; x <= n; x += lowbit(x))
	{
		long long ny = y;
		for(; ny <= m; ny += lowbit(ny))
		{
			tree[x][ny] += z;
		}
	}
}

long long rsum(long long x, long long y)
{
	long long ans = 0;
	for(; x > 0; x -= lowbit(x))
	{
		long long ny = y;
		for(; ny > 0; ny -= lowbit(ny))
		{
			ans += tree[x][ny];
		}
	}
	return ans;
}

long long sum(long long a, long long b, long long c, long long d)
{
	return rsum(c, d) - rsum(c, b - 1) - rsum(a - 1, d) + rsum(a - 1, b - 1);
}

int main()
{
	scanf("%lld%lld", &n, &m);
	while(~scanf("%d", &type))
	{
		if(type == 1)
		{
			scanf("%lld%lld%lld", &p, &q, &k);
			update(p, q, k);
		}
		if(type == 2)
		{
			scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
			printf("%lld\n", sum(a, b, c, d));
		}
	}
	return 0;
}

