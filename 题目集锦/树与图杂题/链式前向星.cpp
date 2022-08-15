#include <bits/stdc++.h>
using namespace std;
int e[100010], ne[100010], h[100010], idx = 0;
long long ans, res;
int n, w[1010];
void add(int a, int b)
{
	idx++
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
}   
void dfs(int k, int fa, int d)
{
	ans = ans + 1LL * w[k] * d;
	for(int i = h[k]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(fa == j) continue;
		dfs(j, k, d + 1);
	}
}
int main()
{
	memset(h, -1, sizeof(h));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	res = 1e18;
	for(int i = 1; i <= n - 1; i++)
	{
		ans = 0;
		dfs(i, 0, 0);
		res = min(res, ans);
	}
	cout << res << endl;
	return 0;
}
