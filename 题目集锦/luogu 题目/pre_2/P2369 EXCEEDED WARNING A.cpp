#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, less<int> > q1;
priority_queue<int, vector<int>, greater<int> > q2;
int main()
{
    int n, m, maxn; cin >> n >> m;
    for (register int i = 1; i <= m; i++)
    {
        int res; cin >> res;
        q1.push(res);
    }
    for (register int i = m + 1, res; i <= n; i++)
    {
        cin >> res;
        if (res < q1.top())
        {
            q1.pop();
            q1.push(res);
        }
    }
    for (register int i = 1; i <= m; i++)
    {
        q2.push(q1.top());
        q1.pop();
    } 
    while(q2.size())
    {
        cout << q2.top() << endl;
        q2.pop();
    }
}
