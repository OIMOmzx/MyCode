#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> S;
       int len=s.length();
			for(int i = 0;i < len;i++)
			{
				if(s[i] == '(' || s[i] == '{' || s[i] == '[')
				{
					S.push(s[i]);
					
				}
				else
				{
                    if(S.empty()==1) return false;
					else if(S.top() == '(' && s[i] != ')')
					{
						return false;
					}
					else if(S.top() == '[' && s[i] != ']')
					{
						return false;
					}
					else if(S.top() == '{' && s[i] != '}')
					{
						return false;
					}
                    else S.pop();
				}
			}
			if(S.empty()==1) return true;
			return false;		
    }
};