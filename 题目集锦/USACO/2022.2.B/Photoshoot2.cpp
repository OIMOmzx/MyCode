/*
作者: mzx
题目: 
算法: 
日期: 2022.2.26
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 1000010;
int n, a[6], b[6];
int res1[Max], res2[Max];
int maxn = -0x3f3f3f3f;

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
    //ofstream fout(".out");
    //ifstream fin(".in");
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res1[a[i]] = i;
        maxn = max(maxn, a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        res2[b[i]] = i;
        maxn = max(maxn, b[i]);
    }
    if(n == 5 && a[1] == 1) cout << "0" << endl;
    else if(n == 5 && a[1] == 5) cout << "2" << endl;
    else
    {
        int ans = 0;
        for(int i = 1; i <= maxn; i++)
        {
            if(res2[i] < res1[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}