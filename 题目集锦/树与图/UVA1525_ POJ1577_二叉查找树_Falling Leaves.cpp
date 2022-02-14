#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;

const int Max = 1010;
struct node
{
    int lc, rc;
    char val;
}tree[Max];
string s, s1;
int cnt = 1;

void create(int k, char v)
{
    if(!tree[k].val)
    {
        tree[k].val = v;
        return;
    }
    else
    {
        if(v < tree[k].val)
        {
            if(!tree[k].lc)
            {
                tree[++cnt].val = v;
                tree[k].lc = cnt;
            }
            else create(tree[k].lc, v);
        }
        if(v > tree[k].val)
        {
            if(!tree[k].rc)
            {
                tree[++cnt].val = v;
                tree[k].rc = cnt;
            }
            else create(tree[k].rc, v);
        }
    }
}

void preorder(int k)
{
    if(!tree[k].val) return;
    cout << tree[k].val;
    preorder(tree[k].lc);
    preorder(tree[k].rc);
}

int main()
{
    while(1)
    {
        s = "";
        memset(tree, 0, sizeof(tree));
        while(cin >> s1 && s1[0] != '*' && s1[0] != '$')
        {
            s += s1;
        }
        //cout << s;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            //cout << "wlllcw";
            create(1, s[i]);
        }
        preorder(1);
        cout << endl;
        if(s1[0] == '$') break;
    }
    return 0;
}