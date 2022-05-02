/*
author: mezt.
time: 2021.12.24
problem: P7960 [NOIP2021] 报数
from: home, MacOS
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int Max = 1000011;
int t, x;
int res, prime[Max], ne[Max];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        f = ch != '-';
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f ? x : -x;
}

bool check(int n)
{
    while(n >= 1)
    {
        if(n % 10 == 7) return 1;
        n /= 10;
    }
    return 0;
}

void is_prime()
{
    for (int i = 1; i <= Max - 10; i++)
    {
        if (prime[i]) continue;
        if (check(i))
        {
            for (int j = i; j <= Max - 10; j += i) prime[j] = 1;
            continue;
        }
        ne[res] = i;
        res = i;
        /*
            「 现在小 r 的上一个数报出了 x，
            小 z 想快速算出他下一个数要报多少 」
            line 52, 53 用来干这个的
        */
    }
}

int main()
{
    is_prime();
    t = read();
    while (t--)
    {
        x = read();
        if (prime[x]) cout << "-1" << endl;
        else printf("%d\n", ne[x]);
    }
    return 0;
}
