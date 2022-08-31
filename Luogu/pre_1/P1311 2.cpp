#include <iostream>
using namespace std;

const int Max = 1000010;
int n, k, p, color, price;
int last[Max], cnt[Max], sum[Max], ans, now;

int main()
{
	cin >> n >> k >> p;
	for(int i = 1; i <= n; i++)
	{
		cin >> color >> price;
		if(price <= p)
		{
			now = i;
		}
		if(now >= last[color])
		{
			sum[color] = cnt[color];
		}
		last[color] = i;
		ans += sum[color];
		cnt[color]++;
	}
	cout << ans << endl;
	return 0;
}