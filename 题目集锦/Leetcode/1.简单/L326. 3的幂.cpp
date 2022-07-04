#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if(n < 3 && n != 1) return false;
        if(n == 1) return true;
        while(n > 1)
        {
            if(n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};