#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int n, a[Max], ans;

struct node
{
    int l, r, val;
}tree1[4 * Max], tree2[4 * Max];

void build1(int k, int l, int r)
{
    tree1[k].l = l;
    tree1[k].r = r;
    if(l == r)
    {
        tree1[k].val = a[l];
        return;
    }
    int mid, lc, rc;
    mid = (l + r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    build1(lc, l, mid);
    build1(rc, mid + 1, r);
    tree1[k].val = max(tree1[lc].val, tree1[rc].val);
}

void build2(int k, int l, int r)
{
    tree2[k].l = l;
    tree2[k].r = r;
    if(l == r)
    {
        tree2[k].val = a[l];
        return;
    }
    int mid, lc, rc;
    mid = (l + r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    build2(lc, l, mid);
    build2(rc, mid + 1, r);
    tree2[k].val = min(tree2[lc].val, tree2[rc].val);
}

int query1(int k, int l, int r)
{
    if(tree1[k].l >= l && tree1[k].r <= r)
    {
        return tree1[k].val;
    }
    int mid, lc, rc;
    int maxn = -0x3f3f3f3f;
    mid = (tree1[k].l + tree1[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(l <= mid)
    {
        maxn = max(maxn, query1(lc, l ,r));
    }
    if(r > mid)
    {
        maxn = max(maxn, query1(rc, l, r));
    }
    return maxn;
}

int query2(int k, int l, int r)
{
    if(tree2[k].l >= l && tree2[k].r <= r)
    {
        return tree2[k].val;
    }
    int mid, lc, rc;
    int minn = 0x3f3f3f3f;
    mid = (tree2[k].l + tree2[k].r) / 2;
    lc = k * 2;
    rc = k * 2 + 1;
    if(l <= mid)
    {
        minn = min(minn, query2(lc, l ,r));
    }
    if(r > mid)
    {
        minn = min(minn, query2(rc, l, r));
    }
    return minn;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build1(1, 1, n);
    build2(1, 1, n);
    //cout << query1(1, 2, 3);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            //cout << i << ", " << j << ":" << query1(1, i, j) << ", " << query2(1, i, j) << endl;
            ans += query1(1, i, j) - query2(1, i, j);
        }
    }
    cout << ans << endl;
    return 0;
}