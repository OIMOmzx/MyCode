#include <iostream>
#include <algorithm>
using namespace std;

int t, a, b;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(a == 1 && b == 1) cout << "0" << endl;
        else cout << 2 * a + b - 2 << endl;
    }
    return 0;
}