#include <bits/stdc++.h>
using namespace std;

const long long Max = 10000010;
long long a[Max], tree[Max];
long long n, t, p, q;
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
       cin >> type >> p >> q;
       if(type == 'x')
       {
           update(p, q);
       } 
       if(type == 'y')
       {
           cout << sum(p, q) << endl;
       }
    }
    return 0;
}