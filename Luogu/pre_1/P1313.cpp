/*
(ax + by)(ax + by)....(ax + by)
C(k, n) * (a ^ n) * (b ^ m)
*/
#include <iostream>
#include <cstdio>
using namespace std;

const long long  Max = 1010;
const long long  mod = 10007;
long long dp[Max][Max];

long long quickpow(long long base, long long time)
{
	long long sum = 1, res = base;
	while(time > 0)
	{
		if(time & 1)
		{
            sum *= res;
            sum %= mod;
		}
		time >>= 1;
		res *= res;
        res %= mod;
	} 
	return sum;s
}

long long a, b, k, m, n;

int main()
{
    scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
    dp[1][1] = 1;
    for(long long i = 2; i <= k + 1; i++)
    {
        for(long long j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - 1] % mod) % mod;
        }
    }
    printf("%lld\n", dp[k + 1][k - n + 1] % mod * quickpow(a, n) % mod * quickpow(b, m) % mod);
    return 0;
}