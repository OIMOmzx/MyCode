#include <iostream>
#include <algorithm>
#define Max 10000010
using namespace std;

int n, res1, res2, ans;
struct node
{
    int x, y;
}a[Max];

bool cmp(node p, node q)
{
    if(p.y < q.y) return 1;
    else if(p.y == q.y && p.x < q.x) return 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(a[i].x >= res2)
        {
            ans++;
            res1 = a[i].x;
            res2 = a[i].y;
        }
    }
    cout << ans << endl;
    return 0;
}