#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 10010;
int n, m, p, q, k, a[Max];
char s[Max];
int ans0, cnt0, ans1, cnt1;

int main()
{
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    cin >> n >> m;
    cin >> (s + 1);
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == 'T') a[i] = 1;
        else a[i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> k;
        if(k == 1)
        {
            cin >> p;
            a[p] = !a[p];
            /*
            for(int i = 1; i <= n; i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
    */
        }
        else
        {
            ans0 = -0x3f3f3f3f, ans1 = -0x3f3f3f3f;
            cnt0 = 0, cnt1 = 0;
            cin >> p >> q;
            for(int j = p; j <= q - 1; j++)
            {
                if(a[j] == 0)
                {
                    ans1 = max(ans1, cnt1);
                    cnt1 = 0;
                    if(a[j] == a[j + 1]) cnt0++;
                }
                if(a[j] == 1)
                {
                    ans0 = max(ans0, cnt0);
                    cnt0 = 0;
                    if(a[j] == a[j + 1]) cnt1++;
                }
            }
            cout << max(max(ans1, cnt1), max(ans0, cnt0)) + 1 << endl;
        }
    }
    return 0;
}