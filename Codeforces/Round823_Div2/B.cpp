#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 100010;
int T, n;

struct node
{
    int x, t;
}a[Max];

bool cmp(node k, node p)
{
    if(k.x < p.x) return 1;
    return 0;
}

double kabs(double c)
{
    if(c >= 0) return c;
    return -c;
}

double check(double mid)
{
    double sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i].t;
        sum += kabs(mid - a[i].x);
    }
    return sum;
}

int main()
{
    cin >> T;
    while(T--)
    {
        int maxn = -0x3f3f3f3f;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].x;
            //cout << a[i].x << ", ";
            maxn = max(maxn, a[i].x);
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].t;
        }
        double l = 0, r = double(maxn), mid = (l + r) / 2;
        //cout << r << endl;
        sort(a + 1, a + n + 1, cmp);
        cout << l << ", " << r << endl;
        while(r - l >= 1e-6)
        {
            mid = (l + r) * 1.0 / 2;
            cout << mid << endl;
            if(check(mid) <= check(l)) l = mid + 1e-6;
            else r = mid - 1e-6;
        }
        cout << l << ", " << mid << ", " << r << endl;
    }
    return 0;
}