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
    for(long long i = 1; i <= 2; i++)
    {
        for(long long j = 1; j <= 2; j++)
        {
            for(long long k = 1; k <= 2; k++)
            {
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j]) % m;
            }
        }
    }
    return ans;
}

long long quickpow(long long k)
{
    node base, ans;
    ans.a[1][1] = 1, ans.a[1][2] = 1, ans.a[2][1] = 1;
    ans.a[2][2] = 0;
    base.a[1][1] = 1, base.a[1][2] = 1, base.a[2][1] = 1;
    base.a[2][2] = 0;
    while(k > 0)
    {
        if(k & 1)
        {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        k >>= 1;
    }
    return ans.a[1][1] % m;
}

int main()
{
    scanf("%lld", &n);
    m = 1e9 + 7;
    if(n == 1 || n == 2) printf("1\n");
    else printf("%lld\n", quickpow(n - 2) % m);
    return 0;
}