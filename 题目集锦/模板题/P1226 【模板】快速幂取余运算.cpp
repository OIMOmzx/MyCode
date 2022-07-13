#include<bits/stdc++.h>
using namespace std;
long long a, b, p, ans = 1, res1, res2;
int main()
{
    cin >> a >> b >> p;
    res1 = a, res2 = b;
    while(b > 0)
    {
        if(b % 2 != 0) ans = ans * a % p;
        a = a * a % p;
        b = b >> 1;  
    }
    ans %= p;
    cout << res1 << "^" << res2 << " mod " << p << "=" << a;
    return 0;
}
  