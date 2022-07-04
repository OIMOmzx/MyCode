#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int ans = -INT_MAX, res = 0, len = nums.size();
        for (int i = 0; i < len; i++) 
        {
            if (res < 0) res = 0;
            res += nums[i];
            ans = max(ans, res);
        }
        return ans;
    }   
};