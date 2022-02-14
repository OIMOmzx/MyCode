#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
int a[Max][3], n;
bool flag = 0;
int ans = -INT_MAX;

void dfs(int col, int line, int step)
{
    if(a[col][line] == 1) return;
    else if(col == n) 
    {
        cout << step << endl;
        exit(0);
    }
    else if(line == 1)
    {
        dfs(col + 1, 1, step + 1);
        dfs(col, 2, step + 1);
    }
    else if(line == 2)
    {
        dfs(col + 1, 2, step + 1);
        dfs(col, 1, step + 1);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2];
        if((a[i][1] == 1 && a[i][2] == 1) || (a[i][1] == 1 && a[i - 1][2] == 1) || (a[i][2] == 1 && a[i - 1][1] == 1) || a[1][1] == 1)
        {
            flag = 1;
        }
    }
    if(flag == 1) cout << "Poor" << endl;
    if(flag == 0)
    {
        dfs(1, 1, 0);
    }
    return 0;
}

/*
6
1 0
0 0
1 0
0 0
0 1
0 0
*/  