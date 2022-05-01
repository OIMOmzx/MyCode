#include <iostream>
using namespace std;

const int Max = 1000010;
int n, m, a[Max];
long long sum = 0;

bool check(int x)
{
    //cout << "x: " << x << "  " << endl;
    int ans = 0, res = 0;
    for(int i = 1; i <= n; i++)
    {
        //cout << res << endl;
        if(a[i] > x) return 0;
        if(res + a[i] <= x)
        {
            res += a[i];
            //cout << a[i] << endl;
        }
        else
        {
            ans++;
            res = a[i];
        }
        if(i == n && res != 0) ans++;
    }
    //cout << ans << endl;
    //cout << "fru3neofwdkmlqs;," << endl;
    if(ans <= m) return 1;
    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int l = 0, r = sum, fin;
    while(l < r)
    {
        int mid = (l + r) / 2;
        //cout << mid << endl;
        if(check(mid)) r = mid, fin = mid;
        else l = mid + 1;
    }
    cout << fin << endl;
    return 0;
}