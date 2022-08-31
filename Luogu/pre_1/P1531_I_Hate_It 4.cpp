#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;
int n, t, a[Max], p, q;
char type;

struct node
{
    int l, r, val;
}tree[4 * Max]; 

void build(int k, int l, int r)
{
    tree[k].l = l;
    tree[k].r = r;
    if(l == r)
    {
        tree[k].val = a[l];
        return;
    }
    int mid, lc, rc;
    mid = (l + r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    tree[k].val = max(tree[lc].val, tree[rc].val);
}

void update(int k, int i, int v)
{
    if(tree[k].l == tree[k].r && tree[k].l == i)
    {
        tree[k].val = max(tree[k].val, v);
        return;
    }
    int mid, lc, rc;
    mid = (tree[k].l + tree[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(i <= mid) 
    {
        update(lc, i, v);
    }
    else 
    {
        update(rc, i, v);
    }
    tree[k].val = max(tree[lc].val, tree[rc].val);
}

int query(int k, int l, int r)
{
    if(tree[k].l >= l && tree[k].r <= r)
    {
        return tree[k].val;
    }
    int mid, lc, rc;
    int maxn = -inf;
    mid = (tree[k].l + tree[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(l <= mid)
    {
        maxn = max(maxn, query(lc, l ,r));
    }
    if(r > mid)
    {
        maxn = max(maxn, query(rc, l, r));
    }
    return maxn;
}

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while(t--)
    {
        cin >> type >> p >> q;
        if(type == 'Q') cout << query(1, p, q) << endl;
        if(type == 'U') update(1, p, q);
    }
    return 0;
}