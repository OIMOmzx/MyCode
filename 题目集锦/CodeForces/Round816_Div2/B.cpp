#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long t, n, k, b, s;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> b >> s;
        if(n == 1)
        {
            if(s % k == 0 && s / k == b) cout << s << endl;
            else cout << "-1" << endl;
        }
        else
        {
            long long maxn = n - 1 + (s - (n - 1) * k) / k;
            if(maxn < b) cout << "-1" << endl;
            else if(k * b + n * k < s) cout << "-1" << endl;
            else
            {
                long long ans[100010];
                ans[n] = k * b;
                long long rest = s - k * b;
                for(long long i = 1; i <= n; i++)
                {
                    ans[i] += rest / n;
                }
                rest = rest - n * (rest / n);
                for(long long i = 1; i <= rest; i++)
                {
                    ans[i]++;
                }
                for(long long i = 1; i <= n; i++)
                {
                    cout << ans[i] << " ";
                }
                cout << endl;
                for(int i = 0; i <= 100009; i++)
                {
                    ans[i] = 0;
                }
            }
        }
    }
    return 0;
}