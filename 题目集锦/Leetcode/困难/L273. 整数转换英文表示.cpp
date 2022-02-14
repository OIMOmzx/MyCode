#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) 
    {
        if(num == 0)
        {
            return "Zero";
        }
        string str;
        int i = 0;
        int unit = 0;   
        for(i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000)
        {
            int curNum = num / unit;
            if(curNum != 0)
            {
                num -= curNum * unit;
                str = str + toEnglish(curNum) + thousands[i] + " ";
            }
        }
        while(str.back() == ' ')
        {
            str.pop_back();
        }

        return str;
    }
    string toEnglish(int num)
    {
        string curr;
        int hundred = num / 100;
        num %= 100;
        if(hundred != 0)
        {
            curr = curr + singles[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if(ten >= 2)
        {
            curr = curr + tens[ten] + " ";
            num %= 10;
        }
        if(num > 0 && num < 10)
        {
            curr = curr +singles[num] + " ";
        }
        else if (num >= 10)
        {
            curr = curr + teens[num - 10] + " ";
        }
        return curr;
    }
};