#include <iostream>
#include <algorithm>
using namespace std;

const long long Max = 10000010;
const long long inf = 0x3f3f3f3f3f3f3f;
long long n, a[Max];
long long ans, sum = inf, res;

int main()
{
    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(long long i = 1; i <= n; i++)
    {
        res = 0;
        for(long long j = 1; j <= n; j++)
        {
            //prlong longf("%d %d %d %d ", i, j, abs(j - i), abs(n - j + i));
            long long dis = min(abs(j - i), abs(n - i + j));
            //cout << "dis" << dis << ", ";
            res += a[j] * dis;
        }
        //cout << endl;
        if(sum >= res)
        {
            sum = res;
            ans = i;
        }
    }
    cout << sum;
    return 0;
}