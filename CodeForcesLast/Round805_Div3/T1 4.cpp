#include <iostream>
using namespace std;

long long a[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int main()
{
    long long t, x;
    cin >> t;
    while(t--)
    {
        cin >> x;
        for(long long i = 0; i <= 10; i++)
        {
            if(a[i] <= x && a[i + 1] > x)
            {
                cout << x - a[i] << endl;
            }
        }
    }
    return 0;
}