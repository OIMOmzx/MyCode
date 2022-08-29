#include <bits/stdc++.h>
using namespace std;
int n, ans, tmp, now;
int main()
{
    cin >> n >> now;
    ans = now;
    if(now > 0) tmp = now;
    for(int i = 2; i <= n; i++)
    {
        cin >> now;
        tmp += now;
        if(tmp > ans) ans = tmp;
        if(tmp < 0) tmp = 0;
    }
    cout << ans;
    return 0;
}