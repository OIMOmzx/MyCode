#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

const int Max = 10000010;
const int inf = 0x3f3f3f3f;
int n, a[Max], sum = 0, maxn = -inf, minn = inf;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(a[i], maxn);
        minn = min(a[i], minn);
        sum += a[i];
    }
    cout << fixed << setprecision(2) << (sum - maxn - minn) * 1.0 / (n - 2) << endl;
    return 0;
}