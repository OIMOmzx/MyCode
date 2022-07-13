#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
int n, t, a[Max], tree[Max];
int type, p, q, m;

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int v)
{
    for( ; i <= n; i += lowbit(i))
    {
        tree[i] += v;
    }
}

int rsum(int i)
{
    int res = 0;
    for( ; i > 0; i -= lowbit(i))
    {
        res += tree[i];
    }
    return res;
}

int sum(int l, int r)
{
    return rsum(r) - rsum(l - 1);
}

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i] - a[i - 1]);
    }
    while(t--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> p >> q >> m;
            update(p, m);
            update(q + 1, -m);
        }
        if(type == 2)
        {
            cin >> p;
            cout << rsum(p) << endl;
        }
    }
    return 0;
}