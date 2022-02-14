#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, a[1000010], cnt;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) cnt = abs(a[0]);
        if(i != 0) cnt = __gcd(abs(a[i]), cnt);
    }
    cout << cnt << endl;
    return 0;
}