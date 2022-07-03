#include <iostream>
using namespace std;

const int Max = 1000010;
int tree[Max];
int n, t, a[Max], type, p, q;

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
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while(t--)
    {
        cin >> type >> p >> q;
        if(type == 1)
        {
            update(p, q);
        }
        if(type == 0)
        {
            cout << sum(p, q) << endl;
        }
    }
}