#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, res1 = 1, res2 = 2;
    int cnt = 3;
    cin >> n;
    while(res1 <= n / 2)
    {
        //cout << res1 << ", " << res2 << ", " << cnt << endl;
        if(cnt == n)
        {
            cout << res1 << " " << res2 << endl;
            cnt -= res1;
            res1 ++;
        }
        else if(cnt > n)
        {
            cnt -= res1;
            res1 ++;
        }
        else if(cnt < n)
        {
            res2++;
            cnt += res2;
        }
    }
    return 0;
}