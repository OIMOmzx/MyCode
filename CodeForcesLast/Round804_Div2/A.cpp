#include <iostream>
using namespace std;

int t, n;
bool flag = 0;

int main()
{
    cin >> t;
    while(t--)
    {
        flag = 0;
        cin >> n;
        if(n % 2 == 1) cout << "-1" << endl;
        else
        {
            int k1 = (n + 2) / 2, k2 = (n - 2) / 2;
            if(2 * (k1 ^ 1) == n) cout << "1 1 " << k1 << endl;
            else if(2 * (k2 ^ 1) == n) cout << "1 1 " << k2 << endl;
        }
    }
    return 0;
}