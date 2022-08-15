#include <bits/stdc++.h>
using namespace std;

const long long Max = 1000010;
long long n, a[Max], tree[Max];// sum[Max];
long long p, q, t, m, num = 1;
long long type;

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
    while(cin >> n && n != 0)
    {
        memset(tree, 0, sizeof(tree));
        for(int i = 1; i <= n; i++)
        {
            cin >> p >> q;
            update(p, 1);
            update(q + 1, -1);
        }
        for(int i = 1; i < n; i++)
        {
            cout << rsum(i) << " ";
        }
        cout << rsum(n) << endl;
    }
    return 0;
}