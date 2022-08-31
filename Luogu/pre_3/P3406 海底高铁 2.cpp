#include <bits/stdc++.h>
using namespace std;
const int Max = 10000010;
long long p[Max], a[Max], b[Max], c[Max], s, ans[Max];
int main()
{
	int n, m, i;
	cin >> n >> m;
	for(i = 1; i <= m; i++) cin >> p[i];
	for(i = 1; i < n; i++) cin >> a[i] >> b[i] >> c[i];
	for(i = 1; i <= m - 1; i++)
	{
		ans[min(p[i], p[i + 1])]++;
		ans[max(p[i], p[i + 1])]--;
	}
	for(i = 1; i <= n; i++) ans[i] += ans[i - 1];
	for(i = 1; i < n; i++) s += min(a[i] * ans[i], (b[i] * ans[i] + c[i]));
    cout << s << endl;
    return 0;  
}