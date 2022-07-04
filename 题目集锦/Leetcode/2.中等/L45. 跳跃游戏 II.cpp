#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int l = 0;
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int r = 1; r < n; r++)
        {
            while(l + nums[l] < r) l++;
            ans[r] = ans[l] + 1;
        }
        return ans[n - 1];
    }
};