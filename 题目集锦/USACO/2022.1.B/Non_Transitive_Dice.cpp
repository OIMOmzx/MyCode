/*
作者: mzx
题目: USACO, Jan., Bronze, T2 Non-Transitive Dice
算法: 
日期: 2022.1.29
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

int t, a[5], b[5], c[5];
bool flag1 = 0, flag2;

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
    ofstream fout("Non-Transitive Dice.out");
    ifstream fin("Non-Transitive Dice.in");
    cin >> t;
    while(t--)
    {
        flag1 = 0;
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        cin >> b[1] >> b[2] >> b[3] >> b[4];
        sort(a + 1, a + 4 + 1);
        sort(b + 1, b + 4 + 1);
        if(b[2] >= a[1] && b[3] >= a[2] && b[4] >= a[4] && ((a[4] - a[1] >= 3) || (b[4] - b[1] >= 3))) flag1 = 1;
        if(flag1 == 0)
        {
            cout << "no" << endl;
            continue;
        }
        else cout << "yes" << endl;
    }
    return 0;
}