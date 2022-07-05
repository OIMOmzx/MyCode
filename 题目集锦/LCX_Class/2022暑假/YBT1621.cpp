#include <iostream>
#include <cmath>
using namespace std;

const int Max = 1000010;
int n, a[Max], vis[Max], ans[Max];
int maxn = -0x3f3f3f3f;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		vis[a[i]]++;
		maxn = max(maxn, a[i]);
	}
	for(int i = 1; i <= maxn; i++)
	{
		if(!vis[i]) continue;
		for(int j = i; j <= maxn; j += i)
		{
			ans[j] += vis[i];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[a[i]] - 1); 
	}
}