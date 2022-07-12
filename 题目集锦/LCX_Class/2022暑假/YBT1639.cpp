#include <iostream>
#include <cstdio>
using namespace std;

const long long Max = 10010;
long long a[Max], b[Max];
long long n, m, x, y;
long long d;

void exgcd(long long a, long long b)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return;
    }
    else
    {
        exgcd(b, a % b);
        long long res = x;
        x = y;
        y = res - (a / b) * y;
    }
}

long long CRT()
{
    long long tmp, ans = 0;
    for(long long i = 1; i <= n; i++)
    {
        //cout << a[i] <<", ";
        tmp = m / a[i];
        //cout << tmp << endl;
        exgcd(tmp, a[i]);
        ans = ((ans + tmp * x * b[i]) % m + m) % m;
        //cout << ans << ", " << tmp << ", " << x << ", " << b[i] << ", " << m << endl;
    }
    if(ans % m == 0) return ans;
    return (ans + m) % m;
}

int main()
{
    n = 3;
    a[1] = 23, a[2] = 28, a[3] = 33;
    m = 23 * 28 * 33;
    long long cnt = 0;
    while(~scanf("%lld%lld%lld%lld", &b[1], &b[2], &b[3], &d))
    {
        cnt++;
        if(b[1] == -1 && b[2] == -1 && b[3] == -1 && d == -1)
        {
            break;
        }
        else if(b[1] == 0 && b[2] == 0 && b[3] == 0)
        {
            printf("Case %lld: the next triple peak occurs in %lld days.\n", cnt, (m - d));
        }
        else
        {
            if(CRT() - d == 0) printf("Case %lld: the next triple peak occurs in %lld days.\n", cnt, 21252);
            else printf("Case %lld: the next triple peak occurs in %lld days.\n", cnt, (CRT() - d + m) % m);
        }
    }
    return 0;
}