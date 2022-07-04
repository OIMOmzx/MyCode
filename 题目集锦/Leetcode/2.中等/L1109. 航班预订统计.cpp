#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        int diff[100010] = {0};
        for(auto num : bookings)
        {
            diff[num[0]] += num[2];
            diff[num[1] + 1] -= num[2];
        }
        vector<int> sum;
        sum.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            sum.push_back(sum[i - 1] + diff[i]);
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++)
        {
            ans.push_back(sum[i]);
        }
        return ans;
    }
};