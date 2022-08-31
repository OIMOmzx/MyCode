#include <iostream>
using namespace std;

const int Max = 1000010;
long long type, p, q, y;
long long n, m, ans;

struct node
{
	long long val, lc, rc;
	long long lzt;
}tree[4 * Max];

void build(long long k, long long l, long long r)
{
	tree[k].lc = l;
	tree[k].rc = r;
	if(tree[k].lc == tree[k].rc)
	{
		cin >> tree[k].val;
		return;
	}
	long long mid = (l + r) / 2;
	long long lchild = k * 2, rchild = k * 2 + 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	tree[k].val = tree[lchild].val + tree[rchild].val;
}

void pushdown(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
	tree[lchild].lzt += tree[k].lzt;
	tree[rchild].lzt += tree[k].lzt;
	tree[lchild].val += tree[k].lzt * (tree[lchild].rc - tree[lchild].lc + 1);
	tree[rchild].val += tree[k].lzt * (tree[rchild].rc - tree[rchild].lc + 1);
	tree[k].lzt = 0;
}

void query(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
	if(tree[k].lc >= p && tree[k].rc <= q)
	{
		ans += tree[k].val;
		return;
	}
	if(tree[k].lzt) pushdown(k);
	long long mid = (tree[k].lc + tree[k].rc) / 2;
	if(p <= mid) query(lchild);
	if(q > mid) query(rchild);
}

void change(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
	if(tree[k].lc >= p && tree[k].rc <= q)
	{
		tree[k].val += (tree[k].rc - tree[k].lc + 1) * y;
		tree[k].lzt += y;
		return;
	}
	if(tree[k].lzt) pushdown(k);
	long long mid = (tree[k].lc + tree[k].rc) / 2;
	if(p <= mid) change(lchild);
	if(q > mid) change(rchild);
	tree[k].val = tree[lchild].val + tree[rchild].val;
}

int main()
{
	cin >> n >> m;
	build(1, 1, n);
	while(m--)
	{
		cin >> type >> p >> q;
		if(type == 1)
		{
			cin >> y;
			change(1);
		}
		if(type == 2)
		{
			ans = 0;
			query(1);
			cout << ans << endl;
		}
	}
	return 0;
}
