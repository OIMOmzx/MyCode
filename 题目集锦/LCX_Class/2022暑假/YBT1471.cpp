#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int Max = 100010;
int t, n;
string s;
int trie[Max][11], res = 0;
bool last[Max];
int ans = 0;
bool f = 0, flag = 0;

bool insert(string s)
{
    int len = s.length(), p = 0;
    for(int i = 0; i < len; i++)
    {
        int ch = s[i] - '0' + 1;
        if(trie[p][ch] == 0)
        {
            trie[p][ch] = ++res;
            f = 1;
        }
        p = trie[p][ch];
        if(last[p]) flag = 1;
    }
    last[p] = 1;
    return (flag == 1 || f == 0);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(last, 0, sizeof(last));
        memset(trie, 0, sizeof(trie));
        bool ans = 0;
        res = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            flag = f = 0;
            cin >> s;
            if(insert(s)) ans = 1;
        }
        if(ans == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}