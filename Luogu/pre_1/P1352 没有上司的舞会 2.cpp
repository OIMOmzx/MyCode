/*
作者: mzx
题目: P1352 没有上司的舞会
算法: 树形 dp
日期: 2022.2.5
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int Max = 10010;
vector<int>son[Max];
int r[Max], vis[Max], dp[Max][2];
int n, l, k, root;

void dpn(int root)
{
    dp[root][0] = 0;
    dp[root][1] = r[root];
    for(int i = 0; i < son[root].size(); i++)
    {
        int y = son[root][i];
        dpn(y);
        dp[root][0] += max(dp[y][0], dp[y][1]);
        dp[root][1] += dp[y][0];
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> l >> k;
        son[k].push_back(l);
        vis[l] = 1; 
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            root = i;
            break;
        }
    }
    dpn(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}