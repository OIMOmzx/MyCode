#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int m = 2;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i - j >= 0)
                dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};