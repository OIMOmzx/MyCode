/*
作者: mzx
题目: P1833 樱花
算法: dp
日期: 2022.2.4
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

const int Max = 10010;
int dp[Max], n, t, w[Max], v[Max], s[Max];
int res1, res2, len1, len2, cnt1, cnt2;
bool flag = 0;
char s1[10], s2[10];

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}

int main()
{
    cin >> (s1 + 1) >> (s2 + 1);
    cin >> n;
    len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    for(int i = 1; i <= len1; i++)
    {
        if(s1[i] == ':')
        {
            flag = 1;
            continue;
        }
        else if(flag == 0)
        {
            res1 *= 10;
            res1 += s1[i] - '0';
        }
        else if(flag == 1)
        {
            res2 *= 10;
            res2 += s1[i] - '0';
        }
    }
    cnt1 = res1 * 60 + res2;
    res1 = 0, res2 = 0, flag = 0;
    //cout << res1 << ',' << res2 << endl;
    for(int i = 1; i <= len2; i++)
    {
        if(s2[i] == ':')
        {
            flag = 1;
            continue;
        }
        else if(flag == 0)
        {
            res1 *= 10;
            res1 += s2[i] - '0';
        }
        else if(flag == 1)
        {
            res2 *= 10;
            res2 += s2[i] - '0';
        }
    }
    cnt2 = res1 * 60 + res2;
    t = cnt2 - cnt1;
    for(int i = 1; i <= n; i++)
    {
        w[i] = read(), v[i] = read(), s[i] = read();
    }
    //cout << cnt1 << ", " << cnt2 << endl;
    //cout << t << endl;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == 0)
        {
            for(int j = w[i]; j <= t; j++)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        else
        {
            for(int k = 1; k <= s[i]; k++)
            {
                for(int j = t; j >= w[i]; j--)
                {
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                }
            }
        }
    }
    cout << dp[t] << endl;
    return 0;
}