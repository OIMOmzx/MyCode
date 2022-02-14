#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node *lc, *rc;
} BSTnode, *BSTree;

void insert(BSTree &tree, int v)
{
    if(!tree)
    {
        BSTree s = new BSTnode;
        s -> data = v;
        s -> lc = s -> rc = NULL;
        tree = s;
    }
    else if(v < tree -> data)
    {
        insert(tree -> lc, v);
    }
    else if(v > tree -> data)
    {
        insert(tree -> rc, v);
    }
}

void create(BSTree &tree)
{
    tree = NULL;
    int v;
    cin >> v;
    while(v != -1)
    {
        insert(tree, v);
        cin >> v;
    }
}

BSTree search(BSTree &tree, int k)
{
    if((!tree) || tree -> data == k) return tree;
    else if(k < tree -> data)
    {
        return search(tree -> lc, k);
    }
    else
    {
        return search(tree -> rc, k);
    }
}

void delete(BSTree &tree, int k)
{
    BSTree p = tree;
    BSTree fa = NULL;
    BSTree q, s;
    if(!T) return;
    while(p)
    {
        if(p -> data == k) break;
        fa = p;
        if(p -> data > k)
        {
            p = p -> lc;
        }
        else
        {
            p = p -> rc;
        }
    } 
    if(!p) return;
    if((p -> lc) && (p -> rc)) 
    {
        q = p;
        s = p -> lc;
        while(s -> rc)
        {
            q = s;
            s = s -> rc;
        }
        p -> data = s -> data;
        if(q != p)
        {
            q -> rc = s -> lc;
        }
        else
        {
            q -> lc = s -> lc;
        }
        delete s;
    }
    else
    {
        if(!p -> rc)
        {
            q = p;
            p = p -> lc;
        }
        else if(!p -> lc)
        {
            q = p;
            p = p -> rc;
        }
        if(!fa)  tree = p;
        else if(q == fa -> lc) fa -> lc = p;
        else fa -> rc = p;
        delete q;
    }
}

int main()
{
    return 0;
}