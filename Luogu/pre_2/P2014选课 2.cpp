#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 301;
int h[Max], ne[Max], e[Max], idx;
int dp[Max][301], n, k, m;

void add(int a, int b)
{
	idx++;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
}

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}


void dfs(int root)
{
	for(int i = h[root]; i; i = ne[i])
	{
		int res = e[i];
		dfs(res);
		for(int j = m; j >= 1; j--)
		{
			for(int k = 0; k < j; k++)
			{
				dp[root][j] = max(dp[root][j], dp[res][k] + dp[root][j - k]);
			}
		}
	}
}

int main()
{
	n = read(), m = read();
	m++;
	for(int i = 1; i <= n; i++)
	{
		k = read(), dp[i][1] = read();
		add(k, i);
	}
	dfs(0);
	cout << dp[0][m];
	return 0;
}