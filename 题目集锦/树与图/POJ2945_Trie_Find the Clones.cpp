#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int trie[Max][26], value[Max], ans[Max];
bool last[Max];
int t, l, res = 0;
int p, q;//useless, to input two '0's.
string s[Max];
string ss;

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

void insert(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = s[i] - 'A';
        if(trie[p][ch] == 0)
        {
            trie[p][ch] = ++res;
        }
        p = trie[p][ch];
    }
    last[p] = 1;
}

int search(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        p = trie[p][s[i] - 'A'];
        if(p == 0)
        {
            return 0;
        }
    }
    if(last[p])
    {
        value[p]++;
    }
    return value[p];
}

int main()
{
    t = read(), l = read();
    ss.resize(l);
    for(int i = 1; i <= t; i++)
    {
        scanf("%s", &ss[0]);
        s[i] = ss;
        //cout << s[i] << endl;
        insert(ss);
    }
    p = read(), q = read();
    for(int i = 1; i <= t; i++)
    {
        //cout << s[i] << endl;
        int k = search(s[i]);
        ans[k]++;
    }
    for(int i = 2; i <= t + 1; i++)
    {
        printf("%d\n", ans[i - 1] - ans[i]);
    }
    return 0;
}