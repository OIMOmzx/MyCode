#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

const int Max = 10000010;
int n, res, root, type, k, t;
struct node
{
    int lc, rc;
    int val, pri;
    int num, size;
}tree[Max];

int New(int v)
{
    tree[++res].val = v;
    tree[res].pri = rand();
    tree[res].num = tree[res].size = 1;
    tree[res].rc = tree[res].lc = 0;
    return res;
}

void update(int &p)
{
    tree[p].size = tree[tree[p].lc].size + tree[tree[p].rc].size + tree[p].num;
}

void zag(int &p)//左旋
{
    int t = tree[p].rc;
    tree[p].rc = tree[t].lc;
    tree[t].lc = p;
    tree[t].size = tree[p].size;
    update(p);
    p = t;
}

void zig(int &p)//右旋
{
    int t = tree[p].lc;
    tree[p].lc = tree[t].rc;
    tree[t].rc = p;
    tree[t].size = tree[p].size;
    update(p);
    p = t;
}

void Insert(int &p, int v)
{
    if(!p)
    {
        p = New(v);
        //cout << tree[p].val << "," << tree[p].pri << endl;
        return;
    }
    tree[p].size++;
    if(tree[p].val == v)
    {
        tree[p].num++;
        return;
    }
    else if(tree[p].val < v)
    {
        Insert(tree[p].rc, v);
        if(tree[p].pri < tree[tree[p].rc].pri)
        {
            zag(p);
        }
    }
    else if(tree[p].val > v)
    {
        Insert(tree[p].lc, v);
        if(tree[p].pri < tree[tree[p].lc].pri)
        {
            zig(p);
        }
    }
}

void Delete(int &p, int v)
{
    if(!p) return;
    tree[p].size--;
    if(v == tree[p].val)
    {
        if(tree[p].num > 1)
        {
            tree[p].num--;
            return;
        }
        if(!tree[p].lc || tree[p].rc)
        {
            p = tree[p].lc + tree[p].rc;
        }
        else if(tree[tree[p].lc].pri > tree[tree[p].rc].pri)
        {
            zig(p);
            Delete(tree[p].rc, v);
        }
        else 
        {
            zag(p);
            Delete(tree[p].lc, v);
        }
        return;
    }
    if(v < tree[p].val) Delete(tree[p].lc, v);
    else Delete(tree[p].rc, v);
}

int getpre(int v)
{
    int p = root;
    int cnt = -1;
    while(p)
    {
        if(tree[p].val < v)
        {
            cnt = tree[p].val;
            p = tree[p].rc;
        }
        else
        {
            p = tree[p].lc;
        }
    }
    return cnt;
}

int getnext(int v)
{
    int p = root;
    int cnt = -1;
    while(p)
    {
        if(tree[p].val > v)
        {
            cnt = tree[p].val;
            p = tree[p].lc;
        }
        else
        {
            p = tree[p].rc;
        }
    }
    return cnt;
}

int queryrank(int k, int v)
{
    if(!k) return 0;
    if(tree[k].val == v)
    {
        return tree[tree[k].lc].size + 1;
    }
    else if(v > tree[k].val)
    {
        return tree[tree[k].lc].size + tree[k].num + queryrank(tree[k].rc, v);
    }
    else 
    {
        return queryrank(tree[k].lc, v);
    }
}

int querynum(int k, int v)
{
    if(!k) return 0;
    if(v <= tree[tree[k].lc].size)
    {
        return querynum(tree[k].lc, v);
    }
    else if(v > tree[tree[k].lc].size + tree[k].num)
    {
        return querynum(tree[k].rc, v - tree[tree[k].lc].size - tree[k].num);
    }
    else
    {
        return tree[k].val;
    }
}

void Inorder(int t)
{
    if(t == 0) return;
    Inorder(tree[t].lc);
    cout << tree[t].val << endl;
    Inorder(tree[t].rc);
}

int main()
{
    srand(time(0));
    cin >> t;
    while(t--)
    {
        cin >> type >> k;
        if(type == 1)
        {
            Insert(root, k);
        }
        if(type == 2)
        {
            Delete(root, k);
        }
        if(type == 3)
        {
            cout << queryrank(root, k) << endl;
        }
        if(type == 4)
        {
            cout << querynum(root, k) << endl;
        }
        if(type == 5)
        {
            cout << getpre(k) << endl;
        }
        if(type == 6)
        {
            cout << getnext(k) << endl;
        }
    }
    return 0;
}