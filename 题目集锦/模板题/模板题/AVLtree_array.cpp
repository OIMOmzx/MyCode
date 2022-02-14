/*
This is a facinating program!!
AVLtree array

time : 2022.1.21
author : mezt
from : zls, MacOS
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Max = 10000010;
struct AVLnode
{
    int data;
    int height;
    int lc, rc;
}tree[Max];
int cnt = 0;

int Height(int T)
{
    if(T == 0) return 0;
    return tree[T].height;
}

void update(int T)
{
    //cout << T << ", ";
    tree[T].height = max(Height(tree[T].lc), Height(tree[T].rc)) + 1;
    //cout << tree[T].data << ":" << tree[T].height << endl;
}

int LL_Rotation(int T)
{
    int temp = tree[T].lc;
    tree[T].lc = tree[temp].rc;
    tree[temp].rc = T;
    update(T);
    update(temp);
    return temp;
}

int RR_Rotation(int T)
{
    int temp = tree[T].rc;
    tree[T].rc = tree[temp].lc;
    tree[temp].lc = T;
    update(T);
    update(temp);
    return temp;
}

int LR_Rotation(int T)
{
    tree[T].lc = RR_Rotation(tree[T].lc);
    return LL_Rotation(T);
}

int RL_Rotation(int T)
{
    tree[T].rc = LL_Rotation(tree[T].rc);
    return RR_Rotation(T);
}

int insert(int T, int x)
{
    if(T == 0)
    {
        cnt++;
        tree[cnt].lc = tree[cnt].rc = 0;
        tree[cnt].data = x;
        tree[cnt].height = 1;
        return cnt;
    }
    if(tree[T].data == x) return T;
    if(x < tree[T].data)
    {
        tree[T].lc = insert(tree[T].lc, x);
        if(Height(tree[T].lc) - Height(tree[T].rc) == 2)
        {
            if(x < tree[tree[T].lc].data)
            {
                T = LL_Rotation(T);
            }
            else
            {
                T = LR_Rotation(T);
            }
        }
    }
    else 
    {
        tree[T].rc = insert(tree[T].rc, x);
        if(Height(tree[T].rc) - Height(tree[T].lc) == 2)
        {
            if(x > tree[tree[T].rc].data)
            {
                T = RR_Rotation(T);
            }
            else
            {
                T = RL_Rotation(T);
            }
        }
    }
    update(T);
    return T;
}

int adjust(int T)
{
    if(T == 0) return 0;
    if(Height(tree[T].lc) - Height(tree[T].rc) == 2)
    {
        if(Height(tree[tree[T].lc].lc) >= Height(tree[tree[T].lc].rc))
        {
            T = LL_Rotation(T);
        }
        else
        {
            T = LR_Rotation(T);
        }
    }
    if(Height(tree[T].rc) - Height(tree[T].lc) == 2)
    {
        if(Height(tree[tree[T].rc].rc) >= Height(tree[tree[T].rc].lc))
        {
            T = RR_Rotation(T);
        }
        else
        {
            T = RL_Rotation(T);
        }
    }
    update(T);
    return T;
}

int Delete(int T, int x)
{
    if(T == 0) return 0;
    if(tree[T].data == x)
    {
        if(tree[T].rc == 0)
        {
            int temp = T;
            T = tree[T].lc;
        }
        else
        {
            int temp;
            temp = tree[T].rc;
            while(tree[temp].lc)
            {
                temp = tree[temp].lc;
            }
            tree[T].data = tree[temp].data;
            tree[T].rc = Delete(tree[T].rc, tree[T].data);
            update(T);
        }
        return T;
    }
    if(tree[T].data > x)
    {
        tree[T].lc = Delete(tree[T].lc, x);
    }
    if(tree[T].data < x)
    {
        tree[T].rc = Delete(tree[T].rc, x);
    }
    update(T);
    T = adjust(T);
    return T;
}

void Inorder(int T)
{
    if(T == 0) return;
    Inorder(tree[T].lc);
    cout << tree[T].data << " " << tree[T].height << endl;
    Inorder(tree[T].rc);
}

int create(int T)
{
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        T = insert(T, x);
    }
    return T;
}

int main()
{
    int res = create(0);
    int root = Delete(res, 15);
    Inorder(res);
    return 0;
}