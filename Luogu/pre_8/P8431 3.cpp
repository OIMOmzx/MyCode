#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 110;
int a[Max], b[Max];

long long rev(long long n)
{
	long long ans = 0;
	while(n > 0)
	{
		ans = ans * 10 + n % 10;
		n /= 10;
	}
	return ans;
}
int main()
{
	long long t, k;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &k);
		memset(b, 0, sizeof(b));
		long long res = k, cnt = 0, ans = 0;;
		bool flag = 1;
		while(res > 0)
		{
			a[++cnt] = res % 10;
			res /= 10;
		}
		b[cnt] = 1;
		for(int i = cnt; i > 0; i--)
		{
			if(a[i] == 9) b[cnt - i + 1] = 9;
			else
			{
				flag = 0;
				b[cnt - i + 1] = a[i] + 1;
				break;
			}
		}
		if(flag)
		{
			printf("%lld\n", k + 1);
			continue;
		}
		for(int i = cnt; i > 0; i--)
		{
			ans = ans * 10 + b[i];
		}
		if(a[1] != 9)
		{
			ans = min(ans, rev(k + 1));
		}
		printf("%lld\n", ans - 1);
	}
	return 0;
}