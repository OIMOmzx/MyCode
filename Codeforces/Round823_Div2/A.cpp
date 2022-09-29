#include <iostream>
using namespace std;

int t, n, c;
int a[1010];
int vis[1010];

int main()
{
    cin >> t;
    while(t--)
    {
        for(int i = 1; i <= 1009; i++)
        {
            vis[i] = 0;
        }
        int ans = 0;
        cin >> n >> c;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            vis[a[i]]++;
        }
        for(int i = 1; i <= 110; i++)
        {
            if(vis[i] != 0)
            {
                if(vis[i] > c) ans += c;
                else ans += vis[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}