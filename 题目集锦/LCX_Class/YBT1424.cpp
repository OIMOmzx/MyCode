#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int Max = 1000010;
int t, l, w, n;

struct node
{
    double l;
    double r;
}a[Max]; 

bool cmp(node x, node y)
{
    if(x.l < y.l) return 1;
    return 0;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> w;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            int pos, r;
            cin >> pos >> r;
            double res = sqrt(r * 1.0 * r * 1.0 - (w / 2.0) * (w / 2.0)); 
            if(r <= w / 2) continue;
            cnt++;
            a[cnt].l = pos - res;
            a[cnt].r = pos + res;
        }
        sort(a + 1, a + cnt + 1, cmp);
        double len = 0;
        int ans = 0;
        bool flag = 1;
        while(len < l)
        {
            ans++;
            double res = len;
            for(int k = 1; a[k].l <= res && k <= cnt; k++)
            {
                if(a[k].r > len) len = a[k].r;
            }
            if(res == len && len < l)
            {
                flag = 0;
                cout << "-1" << endl;
                break;
            }
        }
        if(flag == 1)
        {
            cout << ans << endl;
        }
    }
    return 0;
}