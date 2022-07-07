#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const long long Max = 100010;
long long a[Max], type, p, q, tree[Max];
long long n, t;

long long lowbit(long long x)
{
	return x & (-x);
}

void update(long long i, long long v)
{
	for( ; i <= n; i += lowbit(i))
	{
		tree[i] += v;
	}
}

long long rsum(long long i)
{
	long long res = 0;
	for( ; i > 0; i -= lowbit(i))
	{
		res += tree[i];
	}
	return res;
}

long long sum(long long l, long long r)
{
	return rsum(r) - rsum(l - 1);
}

int main()
{
    scanf("%lld%lld", &n, &t);
    while(t--)
    {
        scanf("%lld%lld%lld", &type, &p, &q);
        if(type == 0)
        {
        	update(p, q);
		}
		if(type == 1)
		{
			printf("%lld\n", sum(1, q) - sum(1, p - 1));
		}
    }
}