#include <iostream>
using namespace std;

const int Max = 100010;
long long a[Max], b[Max], m = 1, n;

void exgcd(long long a, long long b, long long &d, long long &x, long long &y)
{
    if(b == 0)
    {
        d = a;
        x = 1, y = 0;
        return;
    }
    else
    {
        exgcd(b, a % b, d, x, y);
        long long ress = x;
        x = y;
        y = ress - (a / b) * y;
    }
}

long long CRT()
{
    long long ans = 0, res, x, y, d;
    for(long long i = 1; i <= n; i++)
    {
        res = m / a[i];
        exgcd(res, a[i], d, x, y);
        ans = ((ans + res * x * b[i]) % m + m) % m;
    }
    return (ans + m) % m;
}

int main()
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        m *= a[i];
    }
    //cout << m << endl;
    printf("%lld\n", CRT());
    return 0;
}