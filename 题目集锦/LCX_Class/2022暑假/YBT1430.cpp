#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int Max = 1000010;
struct node
{
    long long time, value;
}a[Max];
long long n, ans;

bool cmp(node x, node y)
{
    if(x.time < y.time) return 1;
    else if(x.time == y.time && x.value > y.value) return 1;
    return 0;
}

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].time >> a[i].value;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        q.push(a[i].value);
        if(q.size() > a[i].time)
        {
            q.pop();
        }
    }
    while(!q.empty())
    {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}