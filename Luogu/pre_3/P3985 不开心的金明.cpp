/*
warning : Only 60pts
作者: mzx
题目: P3985 不开心的金明
算法: dp
日期: 2022.2.6
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 10000010;
int t, n;
int w[Max], v[Max], dp[Max];

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
    cin >> t >> n;
    for(int i = 1; i <= t; i++)
    {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= t; i++)
    {
        for(int j = n; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n];
    return 0;
}