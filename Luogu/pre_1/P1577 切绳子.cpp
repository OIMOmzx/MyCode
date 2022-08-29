#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Max = 1000010;
double x;
int n, tar;
int a[Max];
int l, r = 1145141414, mid, ans;

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
        cin >> x;
        a[i] = x * 100;
    }
    //cout << r << endl;
    while(r > l)
    {
        mid = (l + r) / 2;
        if(mid == 0) break;
        //cout << l << ", " << r << ", " << mid << ": " << cut(mid) << endl;
        if(cut(mid) < tar) r = mid;
        else l = mid + 1, ans = mid;
    }
    cout << fixed << setprecision(2) << ans * 1.0 / 100 << endl;
    return 0;
}