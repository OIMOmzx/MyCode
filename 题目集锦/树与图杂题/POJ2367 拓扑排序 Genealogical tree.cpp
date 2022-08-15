#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int Max = 100010;
int n, k;
int in[100010];
stack<int> q;
vector<int> edge[Max];
vector<int> ans;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        while(cin >> k && k)
        {
           edge[i].push_back(k);
           in[k]++; 
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty())
    {
        int p = q.top();
        q.pop();
        ans.push_back(p);
        cout << p << " ";
        //cout << edge[p].size() << ", ";
        for(int i = 0; i < edge[p].size(); i++)
        {
            int y = edge[p][i];
            //cout << y << ", ";
            if(y)
            {
                in[y]--;
                if(in[y] == 0) q.push(y);
            }
        }
    }
    return 0;
}
/*
5
0
4 5 1 0
1 0
5 3 0
3 0
*/