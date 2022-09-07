#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100010];

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int maxn1 = -0x3f3f3f3f, maxn2 = -0x3f3f3f3f;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(i >= 2) maxn2 = max(maxn2, abs(a[i] - a[i - 1]));
            maxn1 = max(maxn1, a[i]);
        }
        //cout << maxn1 << ", " << maxn2 << ", " << a[1] << endl;
        cout << max(maxn2, max(maxn1 - a[1], abs(a[n] - a[1]))) << endl;
    }
    return 0;
}