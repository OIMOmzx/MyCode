/*
    author : mezt.
    write in : FZ, ubuntu NOI Linux2
    time : 2021.10.15
    using : sublime task
*/
#include<bits/stdc++.h>
using namespace std;
int n, num, tl, res, dp[100010], maxn = -INT_MAX, ans = -INT_MAX;
int main()
{
    //freopen("1113.in", "r", stdin);
    //freopen("1113.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num >> tl;
        if(num == 1) cin >> res, dp[1] = tl;
        else
        {
            while(cin >> res && res != 0)
            {
                //cout << res << " ";
                maxn = max(maxn, dp[res]);
                //cout << maxn << " ";
            }
            //cout << endl;
            dp[num] = maxn + tl;
        }
        maxn = -INT_MAX;
    }
    /*
    for(int i = 1; i <= n; i++)
    {
        cout << dp[i] << ", ";
    }
    */
    //cout << endl;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}