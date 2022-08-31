#include <bits/stdc++.h>
using namespace std;
const int mod = 100000007;
int prime[100000010];
bool vis[100000010];
int main()
{
    unsigned long long n, cnt = 0;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        if(vis[i] == 0) prime[cnt] = i, cnt++;
        for(int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    //cout << cnt << ", ";
    unsigned long long ans = 1;
    for(int i = 0; i < cnt; i++)
    {
        unsigned long long tmp = prime[i];
        prime[i] %= mod;
        while(tmp <= n)
        {
            tmp *= prime[i];
        }
        if(tmp != n) tmp /= prime[i];
        ans *= tmp;
        ans %= mod;
    }
    cout << ans;
    return 0;
}