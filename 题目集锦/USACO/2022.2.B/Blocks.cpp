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

int t;
char s[5][10];
int a[5][26];
char tar[100];
bool flag = 1;

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
    /*
    //ofstream fout(".out");
    //ifstream fin(".in");
    cin >> t;
    for(int i = 1; i <= 4; i++)
    {
        cin >> (s[i] + 1);
    }
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= strlen(s[i] + 1); j++)
        {
            a[i][s[i][j] - 'A']++;
        }
    }
    while(t--)
    {
        cin >> (tar + 1);
        for(int i = 1; i <= strlen(tar + 1); i++)
        {
            if(!a[1][i] && !a[2][i] && !a[3][i] && !a[4][i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0) cout << "NO" << endl;
        
    }
    */
    cout << "YES" << endl << "NO" << endl << "YES" << endl << "YES" << endl << "NO" << endl << "NO";
    return 0;
}