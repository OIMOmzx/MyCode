#include <iostream>
#include <algorithm>
#include <unistd.h>
using namespace std;

const int Max = 1000010;
long long a[Max], n;
long long maxn = -0x3f3f3f3f3f, minn = 0x3f3f3f3f3f;

long long exabs(long long x)
{
    if(x < 0) return -x;
    return x;
}

long long solve(long long x)
{
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += exabs(a[i] - (x + i - 3));
    }
    return sum;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    //cout << minn << ", " << maxn << endl;
    int l = minn, r = maxn, mid, ans = 0;
    while(r >= l)
    {
        mid = (l + r + 1) / 2;
        //cout << l << ", " << r << ", " << mid<< endl;
        usleep(100000);
        if(solve(mid) <= solve(mid + 1))
        {
            //cout << mid << ":" << solve(mid) << endl;
            //cout << mid + 1 << ":" << solve(mid + 1) << endl;
            r = mid;
        }
        else l = mid + 1;
        if(r - l <= 2 && (l == mid || r == mid))
        {
            if(solve(r) <= solve(l)) mid = r;
            else if(solve(l) < solve(r)) mid = l;
            break;
        }
    }
    //cout << mid << ": ";
    cout << solve(mid) << endl; 
    /*
    cout << "-----------" << endl;
    for(int i = minn; i <= maxn; i++)
    {
        cout << i << ": " << solve(i) << endl;
    }
    */
    return 0;
}