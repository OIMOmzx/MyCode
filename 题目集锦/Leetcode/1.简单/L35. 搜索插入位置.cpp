#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
     {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int ans = len;
        while (left <= right) 
        {
            int mid = ((right - left) / 2) + left;
            if (target <= nums[mid]) 
            {
                ans = mid;
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};