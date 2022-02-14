#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

const int Max = 1000010;
int trie[Max][26];
int last[Max], value[Max];
int res = 0, i = 1;
string word[Max];
string s, s1;

void insert(string s, int k)
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
    last[p] = 1;
    value[p] = k;
}

int search(string s)
{
    int len = s.length(), p = 1;
    for(int i = 0; i < len; i++)
    {
        p = trie[p][s[i] - 'a'];
        if(!p)
        {
            return 0;
        }
    }
    if(last[p]) return value[p];
    return 0;
}

int main()
{
    while(getline(cin, s))
    {
        if(!s.size()) break;
        stringstream ss(s);
        ss >> word[i] >> s1;
        insert(s1, i);
        i++;
    }
    while(cin >> s)
    {
        int k = search(s);
        if(k != 0) cout << word[k] << endl;
        else cout << "eh" << endl;
    }
    return 0;
} 