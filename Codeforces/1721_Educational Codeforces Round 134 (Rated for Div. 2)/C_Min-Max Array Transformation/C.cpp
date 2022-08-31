//挂了
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
vector<int> res;
bool ava[Max * 10];

bool check(int ai, int bi)
{
    for(int i = n; i >= 1; i--)
    {
        //cout << num[i].size() << ", " << b[num[i][0]] << ", " << b[num[i][bi]] << ", " << ava[b[num[ai][bi]]] << endl;
        if(num[i].size() == 1 && b[num[i][0]] == b[num[i][bi]] && ava[b[num[ai][bi]]] == 1)
        {
            //cout << "3ewd";
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
        num.clear();
        res.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]); 
            ava[b[i]] = 1;
        }
        num.push_back(res);
        cout << "3frw" ;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[i] <= b[j])
                {
                    res.push_back(j);
                }
                else continue;
            }
            num.push_back(res);
            res.clear();
        }
        //cout << num[0].size() << endl;
        /*
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= num[i].size() - 1; j++)
            {
                if(check(i, j)) 
                {
                    cout << -(a[i] - b[num[i][j]]) << " ";
                    break;
                }
            }
        }
        cout << endl;
        */
        
        vector<int> ans;
        for(int i = n; i >= 1; i--)
        {
            for(int j = num[i].size() - 1; j >= 0; j--)
            {
                cout << "3frw" ;
                if(check(i, j)) 
                {
                    //cout << a[i] << ", " << b[num[i][j]] << endl;
                    ans.push_back(-(a[i] - b[num[i][j]]));
                    ava[b[num[i][j]]] = 0;
                    break;
                }
            }
        }
        for(int i = 0; i <= ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}