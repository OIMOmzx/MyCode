#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;
int t, mod, n, last, len = 0;
char type;

struct node
{
	int lc, rc, val;
}tree[Max * 4];

void build(int k, int l, int r)
{
    tree[k].lc = l;
    tree[k].rc = r;
    if(l == r)
    {
        tree[k].val = -inf;
        return;
    }
    int mid, lchild, rchild;
    mid = (l + r) / 2;
    lchild = k * 2;
    rchild = k * 2 + 1;
    build(lchild, l, mid);
    build(rchild, mid + 1, r);
    tree[k].val = max(tree[lchild].val, tree[rchild].val);
}


void update(int k, int i, int v)
{
	if(tree[k].lc == tree[k].rc && tree[k].lc == i)
	{
		tree[k].val = max(tree[k].val, v);
		return;
	}
	int mid = (tree[k].lc + tree[k].rc) / 2, lchild = k * 2, rchild = k * 2 + 1;
	if(i <= mid)
	{
		update(lchild, i, v);
	}
	else
	{
		update(rchild, i, v);
	}
	tree[k].val = max(tree[lchild].val, tree[rchild].val);
}

int query(int k, int l, int r)
{
	if(tree[k].lc >= l && tree[k].rc <= r)
	{
		return tree[k].val;
	}
	int maxn = -inf;
	int mid = (tree[k].lc + tree[k].rc) / 2, lchild = k * 2, rchild = k * 2 + 1;
	if(l <= mid)
	{
		maxn = max(maxn, query(lchild, l, r));
	}
	if(r > mid)
	{
		maxn = max(maxn, query(rchild, l, r));
	}
	return maxn;
}

int main()
{
	scanf("%d%d", &t, &mod);
	build(1, 1, t);
	while(t--)
	{
		scanf("%s", &type);
		scanf("%d", &n);
		if(type == 'A')
		{
			//cout << "213ds";
			len++;
			update(1, len, (n + last) % mod);
			//cout << "len: " << len << ", "<< n << ", " << last <<", " << (n + last) % mod << endl;
		}
		if(type == 'Q')
		{
			if(!n) cout << "0" << endl;
			else printf("%d\n", query(1, len - n + 1, len));
			last = query(1, len - n + 1, len);
		}
	}
	return 0;
}