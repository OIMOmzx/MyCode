/*
作者: mzx
题目: USACO, Jan., Bronze, T1 Herdle
算法: 
日期: 2022.1.29
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

int a[27], b[27], c[27];
char mp1[4][4], mp2[4][4];
int ans1, ans2;

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
    ofstream fout("Herdle.out");
    ifstream fin("Herdle.in");
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> mp1[i][j];
            a[mp1[i][j] - 'A' + 1]++;
        }
    }
    for(int i = 1; i <= 3; i ++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> mp2[i][j];
            b[mp2[i][j] - 'A' + 1]++;
        }
    }
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(mp1[i][j] == mp2[i][j])
            {
                ans1++;
                c[mp1[i][j] - 'A' + 1]++;
            }
        }
    }
    for(int i = 1; i <= 26; i++)
    {
        if(a[i] != 0 && b[i] != 0)
        {
            ans2 += min(a[i], b[i]) - c[i];
        }
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}