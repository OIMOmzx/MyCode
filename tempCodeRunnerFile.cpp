#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;
int n, tar, a[Max];
int l = inf, r = -inf, mid;

int cut(int k)
{
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        res += a[i] / k;
    }
    return res;
}

int main()
{
    cin >> n >> tar;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = min(l, a[i]), r = max(r, a[i]);
    }
    cout << l << " " << r;
    while(l < r)
    {
        mid = (l + r + 1) / 2;
        if(cut(mid) <= tar) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}