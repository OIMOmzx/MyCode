#include <iostream>
#include <algorithm>
#define Max 1000010
using namespace std;

int m, n;
bool vis[Max];

struct node
{
    int t, w;
}a[Max];

bool cmp(node x, node y)
{
    return x.w > y.w;
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].t;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].w;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        int res = a[i].t;
        while(res > 0 && vis[res])
        {
            res--;
        }
        if(res > 0) vis[res] = 1;
        else m -= a[i].w;
    }
    cout << m << endl;
    return 0;
}
