#include <bits/stdc++.h>
using namespace std;
int prime[1000010];
bool vis[1000010];
int main()
{
    int k, n, cnt = 0;
    cin >> k >> n;
    for(int i = 2; i <= k; i++)
    {
        if(vis[i] == 0) prime[cnt] = i, cnt++;
        for(int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    int res;
    for(int i = 0; i <= n - 1; i++)
    {
        cin >> res;
        cout << prime[res - 1] << endl;
    }
    return 0;
}