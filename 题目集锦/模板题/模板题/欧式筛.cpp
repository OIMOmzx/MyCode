#include <bits/stdc++.h>
using namespace std;
int prime[1000010];
bool vis[1000010];
int main()
{
    int n, cnt = 0;
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
    for(int i = 0; i < cnt; i++)
    {
        cout << prime[i] << ", ";
    }
    return 0;
}