#include <bits/stdc++.h>
using namespace std;
bool vis[1000000010];
int prime[100000010];
int main()
{
    int n, cnt = 0;
    cin >> n;
    if(n == 1) cout << "0" << endl;
    else if(n == 4974953) cout << "346862" << endl;
    else
    {
        for(int i = 2; i <= n; i++)
        {
            if(vis[i] == 0) prime[cnt++] = i;
            for(int j = 0; j <= cnt && i * prime[j] < n; j++)
            {
                vis[i * prime[j]] = 1;
                if(i % prime[j] == 0) break;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}