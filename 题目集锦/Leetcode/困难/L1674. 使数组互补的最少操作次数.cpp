#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minMoves(vector<int>& nums, int limit) 
    {
        vector<int> cnt(1000010, 0);
        for(int i = 0; i < nums.size() / 2; i++) 
        {
            int a = min(nums[i], nums[nums.size() - i - 1]);
            int b = max(nums[i], nums[nums.size() - i - 1]);
            int res0 = 2;
            int res1 = a + 1;
            int res2 = a + b;
            int res3 = b + limit; 
            int res4 = 2*limit; 
            cnt[res0] += 2;
            cnt[res1] -= 2;
            cnt[res1] += 1;
            cnt[res2] -= 1;
            cnt[res2+1] += 1;
            cnt[res3+1] -= 1;
            cnt[res3+1] += 2;
            cnt[res4+1] -= 2;
        }
        int ans = -INT_MAX;
        int move = 0;
        for (int i = 2; i <= 2 * limit; i++) 
        {
            move += cnt[i];
            ans = min(ans, move);
        }
        return ans;
    }
};