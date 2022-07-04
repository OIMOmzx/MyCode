#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int len1 = haystack.size(), len2 = needle.size();
        for (int i = 0; i + len2 <= len1; i++) 
        {
            bool flag = true;
            for (int j = 0; j < len2; j++) 
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
};
