#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

long long x, y;

long long gcd(long long a, long long b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

void exgcd(long long a, long long b)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b);
	long long res = x;
	x = y;
	y = res - a / b * y;
}

int main()
{
	long long a, b, m, n, l;
	scanf("%lld%lld%lld%lld%lld", &a, &b, &m, &n, &l);
	long long res = gcd(m - n, l), tmp = abs(l / res);
	exgcd(m - n, l);
	if((b - a) % res != 0)
	{
		printf("Impossible");
	}
	else
	{
		printf("%lld", (x * (b - a) / res % tmp + tmp) % tmp);
	}
	return 0;
}
