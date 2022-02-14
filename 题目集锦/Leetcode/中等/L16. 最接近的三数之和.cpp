#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int ans = nums[1] + nums[2] + nums[3];
        int res = abs(ans - target);
        for(int i = 0; i < nums.size() - 1; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            int sum = nums[i] + nums[left] + nums[right];
            while(left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if(res > abs(sum - target))
                {
                    res = min(res, abs(sum - target));
                    ans = sum;
                }
                if(sum > target)
                {
                    right--;
                    continue;
                }
                if(sum < target)
                {
                    left++;
                    continue;
                }
                if(sum == target)
                {
                    return sum;
                }
            }
        }
        return ans;
    }
};