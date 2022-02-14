#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int Max = 100010;
int trie[Max][11];
bool last[Max];
bool flag = 0;
int res = 0, n, t;
string s;

bool insert(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = s[i] - '0';
        if(trie[p][ch] == 0)
        {
            trie[p][ch] = ++res;
        }
        else if(i == len - 1)
        {
            return 1;
        }
        p = trie[p][ch];
        if(last[p])
        {
            return 1;
        }
    }
    last[p] = 1;
    return 0;
}

int main()
{
    cin >> n;
    while(n--)
    {
        memset(trie, 0, sizeof(trie));
        memset(last, 0, sizeof(last));
        res = 1;
        flag = 0;

        cin >> t;
        while(t--)
        {
            cin >> s;
            if(flag)
            {
                continue;
            }
            if(insert(s))
            {
                flag = 1;
            }
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}