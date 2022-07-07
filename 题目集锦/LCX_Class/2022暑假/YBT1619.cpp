#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

const int Max = 1000010;
const int inf = 1000010;
long long l, r, cnt = 0, cnt2 = 0;
long long prime[Max], prime2[Max];
bool vis[Max * 10], vis2[Max * 10];

int main()
{
	for(long long i = 2; i <= inf; i++)
	{
		if(!vis[i]) prime[++cnt] = i;
		for(long long j = 1; j <= cnt && i * prime[j] <= inf; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) continue;
		}
	}
	while(~scanf("%lld%lld", &l, &r))
	{
		memset(prime2, 0, sizeof(prime2));
		memset(vis2, 0, sizeof(vis2));
		if(l == 1) vis2[0] = 1;
		for(long long i = 1; i <= cnt; i++)
		{
			for(long long j = ceil(l * 1.0 / prime[i]); j <= r / prime[i]; j++)
			{
				if(j * prime[i] >= l && j * prime[i] <= r && j > 1)
				{
					vis2[j * prime[i] - l] = 1;
				}
				else continue;
			}
		}
		cnt2 = 0;
		for(long long i = l; i <= r; i++)
		{
			if(!vis2[i - l]) prime2[++cnt2] = i;
		}
		long long maxl, maxr, minl, minr;
		long long maxn = 0, minn = INT_MAX;
		for(long long i = 1; i <= cnt2 - 1; i++)
		{
			long long k = prime2[i + 1] - prime2[i];
			if(k > maxn)
			{
				maxn = k;
				maxl = prime2[i];
				maxr = prime2[i + 1];
			}
			if(k < minn)
			{
				minn = k;
				minl = prime2[i];
				minr = prime2[i + 1];
			}
		}
		if(!maxn) cout << "There are no adjacent primes." << endl;
		else cout << minl << "," << minr << " are closest, " << maxl << "," << maxr << " are most distant." << endl;
	}
	return 0;
}