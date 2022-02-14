#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a >= b) swap(a, b);
    if(a >= c) swap(a, c);
    if(b >= c) swap(b, c);
    if(a + b > c) cout << "Valid" << endl;
    else cout << "Invalid";
    return 0;
}