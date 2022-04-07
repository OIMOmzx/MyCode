#include <iostream>
using namespace std;

unsigned long long t, x, y, z;
bool flag = 0;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    //freopen("math.in", "r", stdin);
    //freopen("math.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> x >> z;
        if(z % x != 0) 
        {
            cout << "-1" << endl;
            flag = 1;
        }
        else
        {
            unsigned long long res = z / x;
            if(res == 1) 
            {
                cout << "1" << endl;
                flag = 1;
            }
            else
            {
                if(x % res == 0) 
                {
                    cout << "-1" << endl;
                    flag = 1;
                }
                else
                {
                    for(unsigned long long i = 1; i <= x; i++)
                    {
                        if(x % i != 0 || res % i != 0) continue;
                        else
                        {
                            if(gcd(x, res / i) == i)
                            {
                                cout << res / i << endl;
                                flag = 1;
                                break;
                            }
                            else continue;
                        }
                    }
                    if(flag == 0) cout << "-1" << endl;
                }
            }
        }
    }
    return 0;
}