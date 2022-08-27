#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int Max = 200010;
int t, n, a[Max], b[Max];
vector<vector<int> > num;

bool check(int ai, int bi)
{
    for(int i = 1; i <= n; i++)
    {
        if(num[i].size() == 1 && num[i][0] == bi && i != ai)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]); 
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                //cout << a[j] << ", " << b[i] << endl;
                if(a[j] <= b[i])
                {
                    cout << "mwjel" << j << ", " << i;
                    //num[j].push_back(i);
                }
                else continue;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= num[i].size() - 1; j++)
            {
                if(check(i, j)) 
                {
                    cout << a[i] - b[num[i][j]] << " ";
                    break;
                }
            }
        }
        cout << endl;
        for(int i = 1; i <= n; i++)
        {
            for(int j = num[i].size() - 1; j >= 0; j--)
            {
                if(check(i, j)) 
                {
                    cout << a[i] - b[num[i][j]] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}