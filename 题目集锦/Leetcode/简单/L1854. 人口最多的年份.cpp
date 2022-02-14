#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
    	long long a[190], b[190];
        memset(a, 0, sizeof(a));
        int ans = 0;
        long long n = 0;
        for(int i = 0; i < logs.size(); i++)
        {
        	a[logs[i][0] - 1950]++;
        	a[logs[i][1] - 1950]--;
		}
        for(int i = 1; i < 101; i++)
        {
            b[i] = b[i - 1] + a[i];
        }
		for(int i = 0; i < 101; ++i)  
		{
            if(b[i] > n)
            {
                n = b[i];
                ans = i;
            }
		}
        return (ans + 1950);
    }
};
