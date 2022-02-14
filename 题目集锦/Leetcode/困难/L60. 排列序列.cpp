#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        vector<int> a(n);
        string ans;
        vector<int> fl(n + 1, 1);
        a[0] = 1;
        k--;
        for (int i = 1; i < n; ++i) 
        {
            a[i] = a[i - 1] * i;
        }
        for(int i = 1; i <= n; ++i) 
        {
            int num = k / a[n - i] + 1;
            for (int j = 1; j <= n; ++j) 
            {
                num -= fl[j];
                if (!num) 
                {
                    ans += (j + '0');
                    fl[j] = 0;
                    break;
                }
            }
            k %= a[n - i];
        }   
        return ans;     
    }
};
