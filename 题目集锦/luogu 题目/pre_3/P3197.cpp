#include <iostream>
using namespace std;

const int mod = 100003;
long long a, b;

long long quickpow(long long base, long long time)
{
	long long sum = 1;
	while(time)
	{
		if(time % 2 == 1)
		{
			sum = sum * base % mod;
		}
		time /= 2;
		base = base * base % mod;
	}
	return sum % mod;
}

int main()
{
	cin >> a >> b;
	cout << (quickpow(a, b) - quickpow(a - 1, b - 1) * a % mod + mod) % mod;
	return 0;
}