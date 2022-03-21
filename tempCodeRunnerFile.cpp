#include <iostream>
using namespace std;

int t, k, n;
bool flag = 1;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> k >> n;
        if(k == 1)
        {
            if(n % 9 == 0) cout << "aya" << endl;
            else
            {
                cout << "baka" << endl;
            }
        }
        else
        {
            int res = 0;
            while(n >= 1)
            {
                int cnt = n % 10;
                if(cnt != 9) flag = 0;
                res++;
                n /= 10;
            }
            if(res % k != 0) flag = 0;
            if(flag == 0) cout << "baka" << endl;
            else cout << "aya" << endl;
        }
    }
    return 0;
}