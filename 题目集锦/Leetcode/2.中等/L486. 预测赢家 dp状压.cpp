#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int length = nums.size();
        auto dp = vector<int>(length);
        for (int i = 0; i < length; i++) 
        {
            dp[i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) 
        {
            for (int j = i + 1; j < length; j++) 
            {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[length - 1] >= 0;
    }
};