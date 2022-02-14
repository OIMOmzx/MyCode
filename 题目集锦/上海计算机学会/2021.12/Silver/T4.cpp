#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 10000010;
long long n, a[Max], t, f[Max], res = 1;

bool cmp(long long x, long long y)
{
    if(x > y) return 1;
    return 0;
}

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            f[res] = a[i] * a[j];
            res++;
        }
    }
    sort(f + 1, f + res, cmp);
    cout << f[t] << endl;
    return 0;
}