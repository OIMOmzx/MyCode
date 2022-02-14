#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (i <= ans) 
            {
                ans = max(ans, i + nums[i]);
                if (ans >= n - 1) return true;
            }
        }
        return false;
    }
};