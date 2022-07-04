#include <iostream>
using namespace std;

const int Max = 100010;
int n, t, type, p, q, tree1[Max], tree2[Max];

int lowbit(int x)
{
	return x & (-x);
}

void update1(int i, int v)
{
	for( ; i <= n; i += lowbit(i))
	{
		tree1[i] += v;
	}
}

void update2(int i, int v)
{
	for( ; i <= n; i += lowbit(i))
	{
		tree2[i] += v;
	}
}


int rsum1(int i)
{
	int res = 0;
	for( ; i > 0; i -= lowbit(i))
	{
		res += tree1[i];
	}
	return res;
}

int rsum2(int i)
{
	int res = 0;
	for( ; i > 0; i -= lowbit(i))
	{
		res += tree2[i];
	}
	return res;
}

int main()
{
	cin >> n >> t;
	while(t--)
	{
		cin >> type >> p >> q;
		if(type == 1)
		{
			update1(p, 1);
			update2(q, 1);
		}
		if(type == 2)
		{
			cout << rsum1(q) - rsum2(p - 1) << endl;
		}
	}
	return 0;
}