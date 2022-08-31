#include <iostream>
#include <vector>
using namespace std;

const int Max = 1000010;
long long n, m, k, x, cnt;
bool vis[Max];
vector<int> ans;

long long quickpow(long long base, long long time)
{
	long long sum = 1;
	while(time)
	{
		if(time % 2 == 1)
		{
			sum = sum * base % cnt;
		}
		time /= 2;
		base = base * base % cnt;
	}
	return sum % cnt;
}

int main()
{
	cin >> n >> m >> k >> x;
	ans.push_back(x);
	while(!vis[(x + m) % n])
	{
		cnt++;
		x = (x + m) % n;
		ans.push_back(x);
		vis[x] = 1;
	}
	//cout << cnt << endl;
	cout << ans[quickpow(10, k) % cnt];
	return 0;
}