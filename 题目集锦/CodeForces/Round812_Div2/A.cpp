#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, x[110], y[110];

int main()
{
    cin >> t;
    while(t--)
    {
        int a = 0, b = 0, c = 0, d = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
            if(x[i] < 0)
            {
                a = min(a, x[i]);
            }
            if(x[i] > 0)
            {
                b = max(b, x[i]);
            }
            if(y[i] < 0)
            {
                c = min(c, y[i]);
            }
            if(y[i] > 0)
            {
                d = max(d, y[i]);
            }
        }
        
        cout << a << ", " << b << ", " << c << ", " << d << endl;
        cout << (abs(a) + abs(b) + abs(c) + abs(d)) * 2 << endl;
    }
    return 0;
}