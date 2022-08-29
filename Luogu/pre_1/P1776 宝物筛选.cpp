#include <bits/stdc++.h>
using namespace std;

const int Max = 110;
int n, t, v[Max], w[Max], s[Max], a[50010], b[50010];
int res = 0, dp[50010];

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
	n = read(), t = read();
	for(int i = 1; i <= n; i++)
	{
		v[i] = read(), w[i] = read(), s[i] = read();
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= s[i]; j = j << 1)
		{
			res++;
			a[res] = v[i] * j;
			b[res] = w[i] * j;
			s[i] -= j;
		}
		if(s[i] > 0)
		{
			int j = s[i];
			res++;
			a[res] = v[i] * j;
			b[res] = w[i] * j;
			s[i] -= j;
		}
	}
	for(int i = 1; i <= res; i++)
	{
		for(int j = t; j >= b[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
		}
	}
	cout << dp[t];
	return 0;
}