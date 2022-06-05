#include <iostream>
using namespace std;

int t, x, y;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> x;
        for(int i = 1; i <= INT_MAX; i++)
        {
            //cout << (x & i) << ", " << (x xor i) << endl;
            if((x & i) > 0 && (x xor i) > 0) 
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}