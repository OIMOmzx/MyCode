#include <iostream>
using namespace std;

const int Max = 1000010;
const int mod = 1e9 + 7;
long long prime[Max], num[Max];
bool vis[Max];
long long cnt = 0;

int main()
{
	long long n;
	cin >> n;
	n = n;
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) continue;
		}
	}
	for(int i = 1; i <= cnt; i++)
	{
		long long res = 1;
		while(res <= n)
		{
			res *= prime[i];
			num[prime[i]] += n / res;
		}
	}
	long long ans = 1;
	for(int i = 1; i <= cnt; i++)
	{
		//cout << prime[i] << ", " << num[prime[i]] << endl;
		ans = ans * (2 * num[prime[i]] + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}