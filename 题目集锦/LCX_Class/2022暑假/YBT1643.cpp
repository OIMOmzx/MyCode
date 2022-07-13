#include <iostream>
#include <cstring>
using namespace std;

long long n, m;

struct node
{
    long long a[20][20];
    node()
    {
        memset(a, 0, sizeof(a));
    }
};

node mul(node x, node y)
{
    node ans;
    for(long long i = 1; i <= 3; i++)
    {
        for(long long j = 1; j <= 3; j++)
        {
            for(long long k = 1; k <= 3; k++)
            {
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j]) % m;
            }
        }
    }
    return ans;
}

long long quickpow(long long k)
{
    node ans, base;
    for(int i = 1; i <= 3; i++)
    {
        ans.a[i][i] = 1;
    }
    base.a[1][1] = 1, base.a[1][2] = 1, base.a[2][2] = 1, base.a[2][3] = 1, base.a[3][2] = 1;
    while(k > 0)
    {
        if(k & 1)
        {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        k >>= 1;
    }
    return ans.a[1][1] + ans.a[1][2] + ans.a[1][3] % m;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", quickpow(n - 1) % m);
    return 0;
}