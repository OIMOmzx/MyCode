#include <iostream>
using namespace std;

int n, W, w[100010], v[100010];
int dp[100010];

int main()
{
    cin >> n >> W;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = W; j >= 0; j--)
        {
            if(j > w[i]) dp[j] = (dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W];
    return 0;
}