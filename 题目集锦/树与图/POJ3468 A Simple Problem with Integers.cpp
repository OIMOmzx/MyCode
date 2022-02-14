#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const long long Max = 10000010;

long long n, t;
long long a[Max * 4];
char type;
long long p, q, m;

struct node
{
    long long l, r, val, lazy;
}tree[4 * Max]; 

inline long long read()
{
    long long s = 0, f = 0;
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

void pushdown(long long k)
{
    long long lc, rc;
    lc = k * 2;
    rc = k * 2 + 1;
    if(tree[k].lazy)
    {
        tree[lc].lazy += tree[k].lazy;
        tree[lc].val += tree[k].lazy * (tree[lc].r - tree[lc].l + 1);
        tree[rc].lazy += tree[k].lazy;
        tree[rc].val += tree[k].lazy * (tree[rc].r - tree[rc].l + 1);
        tree[k].lazy = 0;
    }
}

void build(long long k, long long l, long long r)
{
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lazy = 0;
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
    tree[k].val = tree[lc].val + tree[rc].val;
}

void update(long long k, long long l, long long r, long long v)
{
    if(tree[k].l == l && tree[k].r == r)
    {
        tree[k].val += v * (tree[k].r - tree[k].l + 1);
        tree[k].lazy += v;
        return;
    }
    pushdown(k);
    long long mid, lc, rc;
    mid = (tree[k].l + tree[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(r <= mid) 
    {
        update(lc, l, r, v);
    }
    else 
    {
        if(l > mid)
        {
            update(rc, l, r, v);
        }
        else
        {
            update(lc, l, mid, v);
            update(rc, mid + 1, r, v);
        }
    }
    tree[k].val = tree[lc].val + tree[rc].val;
}

long long query(long long k, long long l, long long r)
{
    if(tree[k].l == l && tree[k].r == r)
    {
        return tree[k].val;
    }
    pushdown(k); 
    long long mid, lc, rc;
    long long maxn = 0;
    mid = (tree[k].l + tree[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(r <= mid)
    {
        return query(lc, l, r);
    }
    else 
    {
        if(l > mid)
        {
            return query(rc, l, r);
        }
        else
        {
            return query(lc, l, mid) + query(rc, mid + 1, r);
        }
    }
}

int main()
{
    cin >> n >> t;
    for(long long i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    build(1, 1, n);
    while(t--)
    {
        cin >> type;
        if(type == 'Q')
        {
            p = read(), q = read();
            cout << query(1, p, q) << endl;
        }
        if(type == 'C')
        {
            p = read(), q = read(), m = read();
            update(1, p, q, m);
        }
    }
    return 0;
}