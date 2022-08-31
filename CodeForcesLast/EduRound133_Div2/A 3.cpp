#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int res = n / 6;
        if(n == 1)
        {
            cout << "2" << endl;
        }
        else if(n % 6 == 0)
        {
            cout << n / 3 << endl;
        }
        else if(n % 6 == 1)
        {
            cout << res * 2 + 1 << endl;
        }
        else if(n % 6 == 2)
        {
            cout << res * 2 + 1 << endl;
        }
        else if(n % 6 == 3)
        {
            cout << res * 2 + 1 << endl;
        }
        else if(n % 6 == 4)
        {
            cout << res * 2 + 2 << endl;
        }
        else if(n % 6 == 5)
        {
            cout << res * 2 + 2 << endl;
        }
    }
    return 0;
}