#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const long long Max = 1000010;
long long n, a[Max], tree[Max];// sum[Max];
long long p, q, t, m, num = 1;
long long type;

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
    n = read(), t = read();
    for(long long i = 1; i <= n; i++)
    {
        a[i] = read();
        update(i, a[i] - a[i - 1]);
    }
    while(t--)
    {
        type = read();
        if(type == 1)
        {
            p = read(), q = read(), m = read();
            update(p, m);
            update(q + 1, -m);
        }
        if(type == 2)
        {
            p = read();
            cout << rsum(p) << endl;
        }
    }
}