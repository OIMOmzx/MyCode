#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
long long n, tar, a[Max];
long long l, r = -0x3f3f3f3f, mid;
long long ans;

long long maxn(long long a, long long b)
{
    if(a >= b) return a;
    return b;
}

bool isvalid()
{
    long long res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] - mid >= 0) res += a[i] - mid;
    }
    //cout << res << endl;
    if(res >= tar) return 1;
    else return 0;
}

int main()
{
    cin >> n >> tar;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = maxn(r, a[i]);
    }
    while(l < r)
    {
        mid = (l + r) / 2;
        //cout << mid << ", ";
        if(isvalid()) ans = mid, l = mid + 1;
        else r = mid;
    }
    cout << ans << endl;
    return 0;
}