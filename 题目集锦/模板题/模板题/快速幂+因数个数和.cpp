#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const long long Max = 1000010;
const long long mod = 9901;
long long prime[Max], num[Max];
bool vis[Max];
long long cnt = 0;

long long quickpow(long long base, long long time)
{
	long long sum = 1;
	while(time)
	{
		if(time % 2 == 1)
		{
			sum = sum % mod * base % mod;
		}
		time /= 2;
		base = base * base % mod;
	} 
	return sum;
}

long long sum(long long p, long long n)
{
    if(n == 0) return 1;
    if(n & 1)
    {
        return (sum(p, n / 2) * (1 + quickpow(p, n / 2 + 1))) % mod;
    }
    else
    {
        return (sum(p, n / 2 - 1) * (1 + quickpow(p, n / 2 + 1)) + quickpow(p, n / 2)) % mod;
    }
}

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	/*
	vis[1] = 1;
	for(long long i = 1; i <= a; i++)
	{
		if(!vis[i]) prime[++cnt] = i;
		for(long long j = 1; j <= cnt && i * prime[j] <= a; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) continue;
		}
	}
	for(long long i = 1; i <= cnt; i++)
	{
		long long res = 0;
		while(a % prime[i] == 0)
		{
			//cout << "mzx" << endl;
			a = a / prime[i];
			res++;
			//cout << res << endl;
		}
		num[i] = res;
	}
	*/
	for(long long i = 2; i <= sqrt(a);)
	{
		if(a % i == 0)
		{
			prime[++cnt] = i;
            num[cnt] = 0;
			while(!(a % i))
			{
				a /= i;
				num[cnt]++;
			}
		}
        if(i == 2) i++;
        else i += 2;
        //cout << " fuwnfinqwaion" << endl;
	}
	if(a != 1)
	{
		prime[++cnt] = a;
		num[cnt] = 1;
	}
	long long ans = 1;
	for(long long i = 1; i <= cnt; i++)
	{
		ans = ans * (sum(prime[i], b * num[i]) % mod) % mod;
	}
	printf("%lld\n", ans % mod);
	return 0;
}