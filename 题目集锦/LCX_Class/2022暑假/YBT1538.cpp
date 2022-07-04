#include <iostream>
#include <cstdio>
using namespace std;

const int Max = 500010;
int n, t, p, q, tree[Max];
char type;

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

int lowbit(int x)
{
	return x & (-x);
}

void update(int i, int v)
{
	for( ; i <= n; i += lowbit(i))
	{
		tree[i] += v;
	}
}

int rsum(int i)
{
	int res = 0;
	for( ; i > 0; i -= lowbit(i))
	{
		res += tree[i];
	}
	return res;
}

int main()
{
	n = read(), t = read();
	while(t--)
	{
		scanf(" %c", &type);
		if(type == 'A')
		{
			p = read();
			printf("%d\n", rsum(p));
		}
		else
		{
			p = read(), q = read();
			if(type == 'B')
			{
				update(p, q);
			}
			if(type == 'C')
			{
				update(p, -q);
			}
		}
	}
	return 0;
}