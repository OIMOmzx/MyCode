#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
struct node
{
    int p, q;
}a[Max], ans[Max];
int n, res = 1;

bool cmp(node x, node y)
{
    if(x.p < y.p) return 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].p >> a[i].q;
    }
    for(int i = 1; i < Max; i++)
    {
        ans[i].q = -INT_MAX;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(i == 1) ans[res].p = a[i].p, ans[res].q = a[i].q;
        else
        {
            if(a[i].p > ans[res].q)
            {
                ans[res + 1].p = a[i].p;
                ans[res + 1].q = a[i].q;
                res++;
            }
            else
            {
                ans[res].q = max(ans[res].q, a[i].q);
            }
        }
    }
    for(int i = 1; i <= res; i++)
    {
        cout << ans[i].p << " " << ans[i].q << endl;
    }
    return 0;
}

/*
5
5 6
1 4
10 10
6 9
8 10

1 4
5 6
6 9
8 10
10 10
*/