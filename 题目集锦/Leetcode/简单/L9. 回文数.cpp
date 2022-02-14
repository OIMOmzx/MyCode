#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution 
{
    public:
    bool isPalindrome(int x)
    {
        if(x < 0 || x % 10 == 0 && x != 0) return false;
        else
        {
            int s = 0;
            while (x > s) 
            {
                s = s * 10 + x % 10;
                x = x / 10;
            }
            return x == s || x == s / 10;
        }
    }
};