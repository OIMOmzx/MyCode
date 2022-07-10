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
