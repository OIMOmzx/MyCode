#include <bits/stdc++.h>
using namespace std;
int prime[1000010];
bool vis[1000010];
int main()
{
    int k, n, cnt = 0;
    cin >> k >> n;
    for(int i = 2; i <= n; i++)
    {
        if(vis[i] == 0) prime[cnt] = i, cnt++;
        for(int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    int a, b, res = 0;
    while(k--)
    {
        cin >> a >> b;
        if(a <= 0 || b > n) 
        {
            cout << "Crossing the line" << endl;
            continue;
        }
        for(int i = 0; i < cnt; i++)
        {
            if(prime[i] >= a && prime[i] <= b) res++;
        }
        //if(res == 0) cout << "Crossing the line";
        cout << res << endl;
        res = 0;
    }
    return 0;
}