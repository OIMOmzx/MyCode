/*
作者: mzx
题目: P8115 Table
算法: 
日期: 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 10000010;
char s[Max], ans[Max], out[Max];
long long dis = 0, start, old_len;
unsigned long long res;

int Ten_To_Sixteen()
{
    int cnt = 2;
    ans[1] = '0', ans[2] = 'x';
    while(res > 0)
    {
        int tmp = res % 16;
        res /= 16;
        if(tmp >= 0 && tmp <= 9)
        {
            ans[++cnt] = char(tmp + 48);
        }
        else if(tmp >= 10 && tmp <= 15)
        {
            ans[++cnt] = char(tmp + 55);
        }
    }
    return cnt;
}

int main()
{
    cin >> (s + 1);
    int len = strlen(s + 1);
    for(int i = 1; i <= len; i++)
    {
        if(s[i] == '{')
        {
            out[++dis] = s[i];
        }
        else if(s[i] == '}' || s[i] == ',')
        {
            int new_len = Ten_To_Sixteen();
            //cout << new_len << ", " << old_len << endl;
            if(new_len <= old_len)
            {
                //cout << "newlen" << new_len << "oldlen" << old_len << endl;
                out[++dis] = ans[1];
                out[++dis] = ans[2];
                for(int i = new_len; i >= 3; i--)
                {
                    out[++dis] = ans[i];
                }
            }
            else if(new_len > old_len)
            {
                //cout << "newlen" << new_len << "oldlen" << old_len << endl;
                for(int i = start; i <= start + old_len - 1; i++)
                {
                    out[++dis] = s[i];
                }
                start = 0;
            }
            res = 0;
            out[++dis] = s[i];
            old_len = 0;
            start = 0;
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            if(!start) start = i, old_len = 0;
            old_len++;
            res *= 10;
            res += (s[i] - '0');
            //cout << "res :" << res << endl;
        }
    }
    for(int i = 1; i <= dis; i++)
    {
        cout << out[i];
    }
    return 0;
}
/*
{9132483294013243,1324329483192480,234123423423421,2134231412314123}
18446744073709551616 
1844674407370955161
*/