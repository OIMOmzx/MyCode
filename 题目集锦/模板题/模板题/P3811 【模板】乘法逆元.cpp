#include <bits/stdc++.h>
using namespace std;
long long n, p;
long long ans[10000010];
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
int main()
{
    n = read(), p = read();
    ans[0] = 0, ans[1] = 1;
    puts("1");
    for(long long i = 2; i <= n; i++) 
    {
     	ans[i] = (long long)(p - p / i) * ans[p % i] % p;
     	printf("%lld\n", ans[i]);
    }
}