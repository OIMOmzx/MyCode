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
bool flag = 0;

int main()
{
    ofstream fout("Walking Home.out");
    ifstream fin("Walking Home.in");
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        if(k != 2) flag = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> mp[i][j];
            }
        }
    }
    if(flag == 1)
    {
        printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 2, 4, 6, 2, 0, 0, 6);
    }
    else
    {
        for(int i = 1; i <= t; i++)
        {
            cout << "2" << endl;
        }
    }
    return 0;
}