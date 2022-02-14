#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        int diff[1000010], sum[1000010];
        memset(diff, 0, sizeof(diff));
        memset(sum, 0, sizeof(sum));
        bool flag = 1;
        int len = -INT_MAX;
        for(int i = 0; i < trips.size(); i++)
        {
            diff[trips[i][1]] += trips[i][0];
            diff[trips[i][2]] -= trips[i][0];
            len = max(len, trips[i][2]);
        }
        for(int i = 1; i <= len + 1; i++)
        {
            sum[i] = sum[i - 1] + diff[i - 1];
        }
        /*
        for(int i = 1; i <= len; i++)
        {
            cout << diff[i] << ", ";
        }
        cout << endl;
        for(int i = 1; i <= len; i++)
        {
            cout << sum[i] << ", ";
        }
        cout << endl;
        */
        for(int i = 1; i <= len + 1; i++)
        {
            if(sum[i] > capacity) flag = 0;
        }
        return flag;
    }
};