#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, t, a[101], dp[25001];
int res, ans;

inline int read() 
{
    int s = 0, f = 0;
    char ch = ' ';

    while (!isdigit(ch)) 
	{
        f |= (ch == '-');
        ch = getchar();
    }

    while (isdigit(ch)) 
	{
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }

    return (f) ? (-s) : (s);
}

int main() 
{
	t = read();
	while(t--) 
	{
		n = read();
		res = 0;
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		ans = 0;
		for(int i = 1; i <= n; i++) 
		{
			a[i] = read();
			res = max(res, a[i]);
		}
		//sort(a + 1, a + n + 1);
		dp[0] = 1;
		for(int i = 1; i <= n; i++) 
		{
			for(int j = a[i]; j <= res; j++) 
			{
				dp[j] += dp[j - a[i]];
			}
		}
		for(int i = 1; i <= n; i++) 
		{
			if(dp[a[i]] == 1) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}