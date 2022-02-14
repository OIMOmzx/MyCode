#include <iostream>
using namespace std;

const int Max = 100010;
const int mod = 1000000007;
long long n, a[Max];

int main()
{
    cin >> n;
    a[0] = 1, a[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 2] * 2 + a[i - 1]) % mod;
    }
    cout << a[n] % mod << endl;
    return 0;
}