#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int n, t, a[Max], b[Max];
int ans;

int fen(int k)
{
    int l = 1, r = n, mid;
    while(l < r)
    {
        mid = (l + r + 1) / 2;
        if(a[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= t; i++)
    {
        cin >> b[i];
    }
    a[n + 1] = 0x3f3f3f3f;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + t + 1); 
    for(int i = 1; i <= t; i++)
    {
        //cout << a[fen(b[i]) + 1] - b[i] << ", " << b[i] - a[fen(b[i])] << endl;
        if(b[i] < a[1]) ans += a[1] - b[i];
        else ans += min(abs(a[fen(b[i]) + 1] - b[i]), abs(b[i] - a[fen(b[i])]));
    }
    cout << ans << endl;
    return 0;
}