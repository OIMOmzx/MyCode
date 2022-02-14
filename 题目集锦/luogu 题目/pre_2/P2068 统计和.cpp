#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const long long Max = 1000010;
long long n, a[Max], tree[Max];// sum[Max];
long long p, q, t, num = 1;
char type;

long long lowbit(long long x)
{
    return x & (-x);
}

void update(long long i, long long v)
{
    for( ; i <= n; i += lowbit(i))
    {
        tree[i] += v;
    }
}

long long rsum(long long i)
{
    long long res = 0;
    for( ; i > 0; i -= lowbit(i))
    {
        res += tree[i];
    }
    return res;
}

long long sum(long long l, long long r)
{
    return rsum(r) - rsum(l - 1);
}

int main()
{
    cin >> n >> t;
    while(t--)
    {
        cin >> type;
        if(type == 'x')
        {
            cin >> p >> q;
            update(p, q);
        }
        if(type == 'y')
        {
            cin >> p >> q;
            cout << sum(p, q) << endl;
        }
    }
}