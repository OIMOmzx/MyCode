#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
int trie[Max][26];
bool last[Max];
int res = 0;

void insert(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = s[i] - 'a';
        if(!trie[p][ch])
        {
            trie[p][ch] = ++res;
        }
        p = trie[p][ch];
    }
    last[p] = true;
}

bool search(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        p = trie[p][s[i] - 'a'];
        if(!p)
        {
            return false;
        }
    }
    return last[p];
}

int main()
{
    return 0;
}