#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;

int t, n, a[Max * 4];
string type;
int p, q;
int num = 1;

struct node
{
    int l, r, val;
}tree[4 * Max];

inline int read()
{
    int s = 0, f = 0;
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
    tree[k].val = tree[lc].val + tree[rc].val;
}

void update(int k, int i, int v)
{
    if(tree[k].l == tree[k].r && tree[k].l == i)
    {
        tree[k].val += v;
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
    tree[k].val = tree[lc].val + tree[rc].val;
}


int query(int k, int l, int r)
{
    if(tree[k].l >= l && tree[k].r <= r)
    {
        return tree[k].val;
    }
    int mid, lc, rc;
    int maxn = 0;
    mid = (tree[k].l + tree[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(l <= mid)
    {
        maxn += query(lc, l ,r);
    }
    if(r > mid)
    {
        maxn += query(rc, l, r);
    }
    return maxn;
}

int main()
{
    int n, m, k, a, b;
    n = read(), m = read();
    build(1, 1, n);
    while(m--)
    {
        k = read(), a = read(), b = read();
        if(k == 0)
        {
            update(1, a, b);
        }
        if(k == 1)
        {
            cout << query(1, a, b) << endl;
        }
    }
    return 0;
}