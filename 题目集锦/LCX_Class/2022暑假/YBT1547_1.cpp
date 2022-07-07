#include <iostream>
#include <cstdio>
using namespace std;

const int Max = 1000010;
long long n, t, type, p, q, a[Max];

struct node
{
	long long lc, rc, val;
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
	long long mid, lchild, rchild;
	mid = (l + r) / 2;
	lchild = k * 2;
	rchild = k * 2 + 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	tree[k].val = tree[lchild].val + tree[rchild].val;
}

void update(long long k, long long i, long long v)
{
	if(tree[k].lc == tree[k].rc && tree[k].lc == i)
	{
		tree[k].val += v;
		return;
	}
	long long mid, lchild, rchild;
	mid = (tree[k].lc + tree[k].rc) / 2;
	lchild = k * 2;
	rchild = k * 2 + 1;
	if(i <= mid) 
    {
        update(lchild, i, v);
    }
    else 
    {
        update(rchild, i, v);
    }
    tree[k].val = tree[lchild].val + tree[rchild].val;
}

long long query(long long k, long long l, long long r)
{
	if(tree[k].lc >= l && tree[k].rc <= r)
    {
        return tree[k].val;
    }
    long long mid, lchild, rchild;
    long long sum = 0;
    mid = (tree[k].lc + tree[k].rc) / 2;
    lchild = k * 2;
    rchild = k * 2 + 1;
    if(l <= mid)
    {
    	sum += query(lchild, l, r);
    }
    if(r > mid)
    {
        sum += query(rchild, l, r);
    }
    return sum;
}

int main()
{
	scanf("%lld%lld", &n, &t);
	build(1, 1, n);
	while(t--)
	{
		scanf("%lld%lld%lld", &type, &p, &q);
		if(type == 0)
		{
			update(1, p, q);
		}
		if(type == 1)
		{
			printf("%lld\n", query(1, p, q));
		}
	}
	return 0;
}