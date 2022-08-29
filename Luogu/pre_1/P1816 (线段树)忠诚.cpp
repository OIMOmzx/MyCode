#include <bits/stdc++.h>
using namespace std;

const long long Max = 1000010;
long long n, t, a[Max], p, q;

struct node
{
    long long l, r, val;
}tree[Max * 4];

void build(long long k, long long l, long long r)
{
    tree[k].l = l;
    tree[k].r = r;
    if(l == r)
    {
        tree[k].val = a[l];
        return;
    }
    long long mid, lc, rc;
    mid = (l + r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    tree[k].val = min(tree[lc].val, tree[rc].val);
}

long long query(long long k, long long l, long long r)
{
    if(tree[k].l >= l && tree[k].r <= r)
    {
        return tree[k].val;
    }
    long long mid, lc, rc;
    long long maxn = 0x3f3f3f3f3f3f;
    mid = (tree[k].l + tree[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(l <= mid)
    {
        maxn = min(maxn, query(lc, l, r));
    }
    if(r > mid)
    {
        maxn = min(maxn, query(rc, l, r));
    }
    return maxn;
}

int main()
{
    cin >> n >> t;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while(t--)
    {
        cin >> p >> q;
        cout << query(1, p, q) << " ";
    }
    return 0;
}