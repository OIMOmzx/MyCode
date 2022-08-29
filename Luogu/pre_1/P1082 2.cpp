#include <iostream>
using namespace std;

long long x, y;

void exgcd(long long a, long long b)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b);
	long long res = x;
	x = y;
	y = res - a / b * y;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	exgcd(a, b);
	x = (x % b + b) % b;
	printf("%lld\n", x);
	return 0;
}