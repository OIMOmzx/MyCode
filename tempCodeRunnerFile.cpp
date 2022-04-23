#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
struct node
{
    int a, b, m;
    int num;
}t[Max];
int n, to[Max];

bool cmp(node x, node y)
{
    if(x.m < y.m) return 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i].a;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i].b;
    }
    for(int i = 1; i <= n; i++)
    {
        t[i].num = i;
        t[i].m = min(t[i].a, t[i].b);
    }
    sort(t + 1, t + n + 1, cmp);
    int res1 = 0, res2 = n + 1;
    for(int i = 1; i <= n; i++)
    {
        if (t[i].m == t[i].a)
        {
            ++res1;
            to[res1] = i;
        } 
        else 
        {
            --res2;
            to[res2] = i;
        }
    }
    int tmp = 0, ans = 0;
    for(int i = 1; i <= n; i++)
    {
        tmp += t[to[i]].a;
        if(tmp > ans)
        {
            ans = tmp;
            ans += t[to[i]].b;
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << t[to[i]].num << " ";
    }
    return 0;
}