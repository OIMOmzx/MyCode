#include <iostream>
using namespace std;

const int Max = 100010;
long long type, p, q, wrk;
long long n, m, ans, y;
long long a[Max];

struct node
{
    long long val, lc, rc;
    long long lzt1, lzt2;
}tree[4 * Max];

void build(long long k, long long l, long long r)
{
    tree[k].lzt2 = 1;
    tree[k].lzt1 = 0;
    tree[k].lc = l;
    tree[k].rc = r;
    if(tree[k].lc == tree[k].rc)
    {
        tree[k].val = a[l];
        return;
    }
    long long mid = (l + r) /2;
    long long lchild = k * 2, rchild = k * 2 + 1;
    build(lchild, l, mid);
    build(rchild, mid + 1, r);
    tree[k].val = tree[lchild].val + tree[rchild].val;
    tree[k].val %= wrk;
}

void pushdown(long long k)
{
    int lchild = k * 2, rchild = k * 2 + 1;
    if(tree[k].lzt2 != 1)
    {
        tree[lchild].lzt2 = (tree[lchild].lzt2 * tree[k].lzt2) % wrk;
        tree[rchild].lzt2 = (tree[rchild].lzt2 * tree[k].lzt2) % wrk;
        tree[lchild].lzt1 = (tree[lchild].lzt1 * tree[k].lzt2) % wrk;
        tree[rchild].lzt1 = (tree[rchild].lzt1 * tree[k].lzt2) % wrk;
        tree[lchild].val = (tree[lchild].val * tree[k].lzt2) % wrk;
        tree[rchild].val = (tree[rchild].val * tree[k].lzt2) % wrk;
        tree[k].lzt2 = 1;
    }
    if(tree[k].lzt1)
    {
        tree[lchild].lzt1 += tree[k].lzt1;
        
        tree[lchild].lzt1 %= wrk;
        tree[rchild].lzt1 += tree[k].lzt1;
        tree[rchild].lzt1 %= wrk;
        tree[lchild].val += tree[k].lzt1 * (tree[lchild].rc - tree[lchild].lc + 1);
        tree[lchild].val %= wrk;
        tree[rchild].val += tree[k].lzt1 * (tree[rchild].rc - tree[rchild].lc + 1);
        tree[rchild].val %= wrk;
        tree[k].lzt1 = 0;
    }
    return;
}

int query(long long k)
{
    long long ansx=0;
    long long lchild = k * 2, rchild = k * 2 + 1;
    if(tree[k].lc >= p && tree[k].rc <= q)
    {
        return tree[k].val;
    }
    pushdown(k);
    long long mid = (tree[k].lc + tree[k].rc) / 2;
    if(p <= mid) ansx += query(lchild);
    if(q > mid) ansx += query(rchild);
    return ansx % wrk;
}

void change1(long long k)
{
    long long lchild = k * 2, rchild = k * 2 + 1;
    if(tree[k].lc >= p && tree[k].rc <= q)
    {
        tree[k].val += (tree[k].rc - tree[k].lc + 1) * y;
        tree[k].val %= wrk;
        tree[k].lzt1 += y;
        tree[k].lzt1 %= wrk;
        return;
    }
    pushdown(k);
    long long mid = (tree[k].lc + tree[k].rc) / 2;
    if(p <= mid) change1(lchild);
    if(q > mid) change1(rchild);
    tree[k].val = tree[lchild].val + tree[rchild].val;
    tree[k].val %= wrk;
}

void change2(long long k)
{
    long long lchild = k * 2, rchild = k * 2 + 1;
    if(tree[k].lc >= p && tree[k].rc <= q)
    {
        tree[k].lzt2 *= y;
        tree[k].lzt2 %= wrk;
        tree[k].lzt1 *= y;
        tree[k].lzt1 %= wrk;
        tree[k].val *= y;
        tree[k].val %= wrk;
        return;
    }
    pushdown(k);
    long long mid = (tree[k].lc + tree[k].rc) / 2;
    if(p <= mid) change2(lchild);
    if(q > mid) change2(rchild);
    tree[k].val = tree[lchild].val + tree[rchild].val;
    tree[k].val %= wrk;
}

int main()
{
    cin >> n >> m >> wrk;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--)
    {
        cin >> type >> p >> q;
        if(type == 1)
        {
            cin >> y;
            change2(1);
        }
        if(type == 2)
        {
            cin >> y;
            change1(1);
        }
        if(type == 3)
        {
            ans = 0;
            cout << query(1) << endl;
            //cout << ans % p << endl;
        }
    }
    return 0;
}
