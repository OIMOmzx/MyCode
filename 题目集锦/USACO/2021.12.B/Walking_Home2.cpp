/*
ID: handsomemzx
TASK: Walking Home
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 60;
int t, n, k, ans;
char mp[Max][Max];

void dfs(int i, int j, int step, int last, int num)
{
    /*
    for(int i = 1; i <= num; i++)
    {
        cout << "   ";
    }
    */
    //cout << i << ", " << j << endl;
    if(step > k) 
    {
        //cout << "ohno" << endl;
        num = 0;
        return;
    }
    if(i == n && j == n)
    {
        //cout << "done!!" << endl;
        ans++;
        return;
    }
    if(mp[i + 1][j] == '.' && i + 1 <= n && (last == 2 || (i == 1 && j == 1)))
    {
        dfs(i + 1, j, step + 1, 1, ++num);
    }
    else if(mp[i + 1][j] == '.' && i + 1 <= n && (last == 1 || (i == 1 && j == 1)))
    {
        dfs(i + 1, j, step, 1, ++num);
    }
    if(mp[i][j + 1] == '.' && j + 1 <= n && (last == 1 || (i == 1 && j == 1)))
    {
        dfs(i, j + 1, step + 1, 2, ++num);
    }
    else if(mp[i][j + 1] == '.' && j + 1 <= n && (last == 2 || (i == 1 && j == 1)))
    {
        dfs(i, j + 1, step, 2, ++num);
    }
    return;
}

int main()
{
    vector<int> res;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> mp[i][j];
            }
        }
        dfs(1, 1, 0, 0, 0);
        res.push_back(ans);
        //cout << ans << endl;
        ans = 0;
    }
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}

/*
7
3 1
...
...
...
3 2
...
...
...
3 3
...
...
...
3 3
...
.H.
...
3 2
.HH
HHH
HH.
3 3
.H.
H..
...
4 3
...H
.H..
....
H...
*/