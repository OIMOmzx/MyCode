#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int Max = 1000010;
int a[Max], b[Max];
int n, t, l, r;
stack<int> s1;
stack<int> s2;

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
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    n = read(), t = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for(int i = 1; i <= n; i++)
    {
        b[i] = read();
    }
    for(int k = 1; k <= t; k++)
    {
        l = read(), r = read();
        int res = 0;
        for(int i = l; i <= r; i++)
        {
            if(s1.empty() && s2.empty())
            {
                s1.push(a[i]), s2.push(b[i]);
                res++;
            }
            
            else
            {
                //cout << s1.top() << ", " << s2.top() << endl;
                while((b[i] >= s2.top() || a[i] == s1.top()))
                {
                    if(!s1.empty() && !s2.empty()) s1.pop(), s2.pop();
                    if(s1.empty() && s2.empty()) break;
                    //cout << "ddd";
                }
                s1.push(a[i]), s2.push(b[i]);
                if(s1.size() == 1 && s2.size() == 1) res++;
            }
            
        }
        cout << res << endl;
        res = 0;
        while(!s1.empty() && !s2.empty())
        {
            s1.pop(), s2.pop();
        }
    }
    return 0;
}