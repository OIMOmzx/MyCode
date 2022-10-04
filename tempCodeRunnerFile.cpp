#include <iostream>
using namespace std;

long long lowbit(long long x)
{
    return x & (-x);
}

long long t, l, r;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        long long ans = 0;
        /*
        for(long long i = l; i <= r; i++)
        {
            if(lowbit(i) < lowbit(i + 1))
            {
                ans++;
            }
        }
        cout << ans << endl;
        */
       if(r % 2 == 0 && l % 2 == 0)
       {
            cout << (r - l) / 2 << endl;
       }
       else if(r % 2 == 1 && l % 2 == 0)
       {
            cout << (r - l) / 2 + 1 << endl;
       }
       else if(r % 2 == 0 && l % 2 == 1)
       {
            cout << (r - l) / 2 + 1 << endl;
       }
       else
       {
            cout << (r - l) / 2 + 1 << endl;
       }
    }
    return 0;
}

/*
4
112 2008
948
117 1177
531
1108 2735
814
377 2008
816
*/