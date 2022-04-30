#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int Max = 10000010;
struct node
{
    double a, b, c;
}t[Max];
int T, n;
double maxn, l, r, lmid, rmid;

double maxx(double a, double b)
{
    if(a > b) return a;
    return b;
}

double calculate(double x)
{
    maxn = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        maxn = max(maxn, t[i].a * x * x + t[i].b * x + t[i].c);
    }
    return maxn;
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> t[i].a >> t[i].b >> t[i].c;
        }
        l = 0, r = 1000;
        while(l + 1e-12 < r)
        {
            lmid = l + (r - l) / 3.0;
            rmid = r - (r - l) / 3.0;
            if(calculate(lmid) > calculate(rmid))
            {
                l = lmid;
            }
            else
            {
                r = rmid;
            }
        }
        cout << fixed << setprecision(4) << calculate(l) << endl;
    }
    return 0;
}