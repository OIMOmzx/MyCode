#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> diff;
        int ans = 0, res = 0;
        for (int i = 0; i < n; ++i) 
        {
            res += diff[i];
            if ((nums[i] + res) % 2 == 0) 
            {
                if (i + k > n) return -1;
                ++ans;
                ++res;
                --diff[i + k];
            }
        }
        return ans;
    }
};