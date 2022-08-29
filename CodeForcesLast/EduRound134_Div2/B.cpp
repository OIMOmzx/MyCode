#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, m, sx, sy, d;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> sx >> sy >> d;
        if((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m) || (sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m))
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << (n - 1 + m - 1) << endl;
        }
    }
    return 0;
}