#include <iostream>
#include <algorithm>
using namespace std;

const long long Max = 1000010;
const long long inf = 0x3f3f3f3f;
long long n, tar, a[Max];
long long l = inf, r = -inf, mid;
long long ans = 0;

long long cut(long long k)
{
    long long res = 0;
    for(long long i = 1; i <= n; i++)
    {
        res += a[i] / k;
    }
    return res;
}
int main()
{
    cin >> n >> tar;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = min(l, a[i]), r = max(r, a[i]);
    }
    l = 0;
    //cout << l << " " << r << endl;
    //cout << cut(114) << endl;
    while(l < r)
    {
        mid = (l + r + 1) / 2;
        //cout << mid << ": " << cut(mid) << endl;
        if(cut(mid) >= tar) ans = mid, l = mid;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}