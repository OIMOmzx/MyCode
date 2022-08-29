#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
int trie[Max][26], value[Max];
bool last[Max];
int n, t, res = 0;
string s;

void insert(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = s[i] - 'a';
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
        p = trie[p][s[i] - 'a'];
        if(!p)
        {
            return false;
        }
    }
    //cout << s << ", " << p << ": " << value[p] << ", " << endl;
    if(last[p] && value[p] == 0) 
    {
        value[p]++;
        return 1;
    }
    else if(last[p] && value[p] >= 1) 
    {
        value[p]++;
        return 2;
    }
    else return 0;
}

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> s;
        insert(s);
    }
    cin >> t;
    while(t--)
    {
        cin >> s;
        int k = search(s);
        if(k == 0) cout << "WRONG" << endl;
        else if(k == 1) cout << "OK" << endl;
        else if(k == 2) cout << "REPEAT" << endl;
    }
    return 0;
}