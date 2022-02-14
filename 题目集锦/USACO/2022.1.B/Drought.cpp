/*
作者: mzx
题目: USACO, Jan., Bronze, T3
算法: 
日期: 2022.1.29
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

const int Max = 1000010;
long long a[Max], n, t, ans, cnt = -0x3f3f3f3f3f3f3f;
bool flag1 = 0, flag2 = 0;

int isvalid()
{
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > a[i - 1]) res += a[i] - a[i - 1];
    } 
	return res;
}

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

long long aabs(long long a)
{
    if(a >= 0) return a;
    else return -a;
}

int main()
{
    ofstream fout("Drought.out");
    ifstream fin("Drought.in");
    cin >> t;
    while(t--)
    {
        cnt = -0x3f3f3f3f3f3f;
        flag1 = 0, flag2 = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt = max(cnt, a[i]);
            if(i >= 3)
            {
                if(a[i] < a[i - 1] && a[i - 1] > a[i - 2] && a[i] != 0 && a[i - 2] != 0)
                {
                    flag1 = 1;
                }
            }
            if(i >= 4)
            {
                if(a[i] == a[i - 1] && a[i] > a[i - 2] && a[i] > a[i - 3])
                {
                    flag2 = 1;
                }
                if(a[i] == a[i - 1] && a[i] < a[i - 2] && a[i] < a[i - 3])
                {
                    flag2 = 1;
                }
            }
        }
        if(isvalid() == cnt && flag1 == 0 && flag2 == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            for(int i = 2; i <= n; i++)
            {
                ans += aabs(a[i] - a[i - 1]);
            }
            cout << ans * 2 << endl;
            ans = 0;
        }
    }
    return 0;
}