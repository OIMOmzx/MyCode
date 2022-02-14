#include <bits/stdc++.h>
using namespace std;

const int Max = 100000001;
bool is[Max];
int prime[Max], n, cnt = 1, t, x;

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

int main()
{
	memset(is, 1, sizeof(is));
	is[0] = 0, is[1] = 0;
	n = read(), t = read();
	for(int i = 2; i <= n; i++)
	{
		if(is[i])
		{
			prime[cnt] = i, cnt++;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
		{
			is[prime[j] * i] = 0;
			if(i % prime[j] == 0) break;
		}
	}
	while(t--)
	{
		x = read();
		cout << prime[x] << endl;
	}
	return 0;
}