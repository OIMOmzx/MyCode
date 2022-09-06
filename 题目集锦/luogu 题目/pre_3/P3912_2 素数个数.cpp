#include <bits/stdc++.h>
using namespace std;

const int Max = 100000001;
bool is[Max];
int prime[Max], n, cnt = 1;

int main()
{
	cin >> n;
	memset(is, 1, sizeof(is));
	is[0] = 1, is[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(is[i])
		{
			prime[cnt] = i;
			cnt++;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
		{
			is[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(is[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}