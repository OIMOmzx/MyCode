#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int t, x;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> x;
        cout << x - lowbit(x) + 1 << " " << x + lowbit(x) - 1 << endl;
    }
    return 0;
}