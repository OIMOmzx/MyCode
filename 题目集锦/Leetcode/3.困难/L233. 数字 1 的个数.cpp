#include <bits/stdc++.h>
using namespace std;
// 参考  Leetcode 官解
class Solution 
{
public:
    int countDigitOne(int n) 
    {
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) 
        {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
};