#include <iostream>
#include <cstdio>
using namespace std;

const int Max = 100010;
int n, t, type, l, r, tree[Max];

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
	scanf("%d%d", &n, &t);
	while(t--)
	{
		scanf("%d", &type);
		if(type == 1)
		{
			scanf("%d%d", &l, &r);
			update(l, 1);
			update(r + 1, 1);
		}
		if(type == 2)
		{
			scanf("%d", &l);
			printf("%d\n", rsum(l) % 2); 
		}
	}
	return 0;	
}
