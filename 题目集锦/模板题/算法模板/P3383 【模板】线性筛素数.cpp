#include <iostream>
#include <algorithm>
using namespace std;
int prime[1000010], k, n, cnt;
bool vis[1000010];
int main()
{
    cin >> k >> n;
    vis[1] = 1;
    for(int i = 2; i <= k; i++)
    {
        if(vis[i] == 0) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= k; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    int res;
    for(int i = 1; i <= n; i++)
    {
        cin >> res;
        cout << prime[res] << endl;
    }
    return 0;
}
