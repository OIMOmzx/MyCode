#include <bits/stdc++.h>
using namespace std;

const int Max = 100010;
int p, q, k, type, n, t, y, ans;

struct node
{
	int lc, rc;
	int a[7];
	int lzt, val;
}tree[4 * Max];

void build(int k, int l, int r)
{
	tree[k].lc = l;
	tree[k].rc = r;
	if(tree[k].lc == tree[k].rc)
	{
		cin >> tree[k].lzt;
		tree[k].a[tree[k].lzt % 7]++;
		return;
	}
	int mid = (l + r) / 2;
	int lchild = k * 2, rchild = k * 2 + 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	tree[k].val = tree[k].lc + tree[k].rc;
	for(int i = 0; i <= 6; i++)
	{
		tree[k].a[i] = tree[lchild].a[i] + tree[rchild].a[i];
	}
}

void change(int k)
{
	int res[7];
	int lchild = k * 2, rchild = k * 2 + 1;
	for(int i = 0; i <= 6; i++)
	{
		res[(i + tree[k].lzt) % 7] = tree[lchild].a[i];
	}
	for(int i = 0; i <= 6; i++)
	{
		tree[lchild].a[i] = res[i];
	}
	for(int i = 0; i <= 6; i++)
	{
		res[(i + tree[k].lzt) % 7] = tree[rchild].a[i];
	}
	for(int i = 0; i <= 6; i++)
	{
		tree[rchild].a[i] = res[i];
	}
}

void pushdown(int k)
{
	int lchild = k * 2, rchild = k * 2 + 1;
	tree[lchild].lzt = tree[k].lzt;
	tree[lchild].lzt %= 7;
	tree[rchild].lzt += tree[k].lzt;
	tree[rchild].lzt %= 7;
	change(k);
	tree[k].lzt = 0;
}

void update(int k)
{
	int res[7];
	if(tree[k].lc >= p && tree[k].rc <= q)
	{
		for(int i = 0; i <= 6; i++)
		{
			res[(i + y) % 7] = tree[k].a[i];
		}
		for(int i = 0; i <= 6; i++)
		{
			tree[k].a[i] = res[i];
		}
		tree[k].lzt += y;
		return;
	}
	if(tree[k].lzt) pushdown(k);
	int mid = (tree[k].lc + tree[k].rc) / 2;
	int lchild = k * 2, rchild = k * 2 + 1;
	if(p <= mid) update(lchild);
	if(q > mid) update(rchild);
	for(int i = 0; i <= 6; i++)
	{
		tree[k].a[i] = tree[lchild].a[i] + tree[rchild].a[i];
	}
}


void query(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
	if(tree[k].lc >= p && tree[k].rc <= q)
	{
		ans += tree[k].a[0];
		return;
	}
	if(tree[k].lzt) pushdown(k);
	long long mid = (tree[k].lc + tree[k].rc) / 2;
	if(p <= mid) query(lchild);
	if(q > mid) query(rchild);
}

int main()
{
	cin >> n;
	build(1, 1, n);
	cin >> t;
	while(t--)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> p >> q >> y;
			update(1);
		}
		if(type == 2)
		{
			ans = 0;
			cin >> p >> q;
			query(1);
			cout << ans << endl;
		}
	}
	return 0;
}

/*
3
2 3 4
6
2 1 3
2 1 2
1 1 3 2
2 1 3
1 1 3 3
2 1 3
*/
