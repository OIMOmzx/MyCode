#include <iostream>
using namespace std;

const int Max = 1000010;
long long type, p, q, y;
long long n, m;
int a[Max];

struct node
{
	long long val, lc, rc;
	long long lzt;
}tree[4 * Max];

void build(long long k, long long l, long long r)
{
	tree[k].lc = l;
	tree[k].rc = r;
	if(l == r)
	{
		tree[k].val = a[l];
		return;
	}
    //cout << tree[k].val << ", " << endl;
	long long mid = (l + r) / 2;
	long long lchild = k * 2, rchild = k * 2 + 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	tree[k].val = tree[lchild].val + tree[rchild].val;
}

void pushdown(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
    if(tree[k].lzt)
    {
	    tree[lchild].val = tree[lchild].rc - tree[lchild].lc + 1 - tree[lchild].val;
	    tree[rchild].val = tree[rchild].rc - tree[rchild].lc + 1 - tree[rchild].val;
        tree[lchild].lzt ^= 1;
	    tree[rchild].lzt ^= 1;
	    tree[k].lzt = 0;
    }
}

int query(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
    long long ans = 0;
	if(tree[k].lc >= p && tree[k].rc <= q)
	{
		return tree[k].val;
	}
	pushdown(k);
	long long mid = (tree[k].lc + tree[k].rc) / 2;
	if(p <= mid) ans += query(lchild);
	if(q > mid) ans += query(rchild);
    return ans;
}

void change(long long k)
{
	long long lchild = k * 2, rchild = k * 2 + 1;
	if(tree[k].lc >= p && tree[k].rc <= q)
	{
		tree[k].val = tree[k].rc - tree[k].lc + 1 - tree[k].val;
		tree[k].lzt ^= 1;
		return;
	}
	pushdown(k);
	long long mid = (tree[k].lc + tree[k].rc) / 2;
	if(p <= mid) change(lchild);
	if(q > mid) change(rchild);
	tree[k].val = tree[lchild].val + tree[rchild].val;
}

int main()
{
	cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        scanf("%1d", &a[i]);
    }
	build(1, 1, n);
	while(m--)
	{
		cin >> type >> p >> q;
		if(type == 0)
		{
			change(1);
		}
		if(type == 1)
		{
			cout << query(1) << endl;
		}
	}
	return 0;
}
