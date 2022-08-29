#include <iostream>
#include <cmath>
using namespace std;

const long long Max = 1010;
long long n, t;
struct node
{
    long long type;
    long long val1, val2;
}a[Max];
long long ans[Max];

int main()
{
    cin >> n >> t;
    for(long long i = 1; i <= n; i++)
    {
        cin >> ans[i];
    }
    for(long long i = 1; i <= t; i++)
    {
        cin >> a[i].type >> a[i].val1 >> a[i].val2;
    }
    for(long long i = t; i >= 1; i--)
    {
        long long fir = a[i].val1, end = a[i].val2;
        if(a[i].type == 1)
        {
            if(fir == end) ans[fir] /= 2;
            else ans[fir] -= ans[end];
        }
        else if(a[i].type == 2)
        {
            if(fir == end) ans[fir] = sqrt(ans[fir]);
            else ans[fir] /= ans[end];
        }
    }
    for(long long i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}