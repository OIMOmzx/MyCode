#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int len = nums.size() - 1;
        for (int i = 0; i <= len; i++) 
        {
            if (nums[i] == val) 
            {
                swap(nums[i--], nums[len--]);
            }
        }
        return len + 1;
    }
};