#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 200010;
int n, L;
double a[Max], b[Max], t[Max];

double minx(double a, double b)
{
    return a < b ? a : b;
}

double maxx(double a, double b)
{
    return a > b ? a : b;
}

int main()
{
    cin >> n >> L;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    double l = 0, r = 1e6;
    while(r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        //cout << mid << endl;
        for(int i = 1; i <= n; i++)
        {
            b[i] = a[i] - mid;
        }
        for(int i = 1; i <= n; i++)
        {
            t[i] = t[i - 1] + b[i];
        }
        double res = -0x3f3f3f3f, minn = 0x3f3f3f3f;
        for(int i = L; i <= n; i++)
        {
            minn = minx(minn, t[i - L]);
            res = maxx(res, t[i] - minn);
        }
        if(res >= 0) l = mid;
        else r = mid;
    }
    cout << int(r * 1000);
    return 0;
}