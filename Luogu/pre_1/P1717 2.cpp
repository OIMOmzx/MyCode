#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int c[Max], n, m, h;
struct node
{
    int a, b;
}p[Max];

struct node1
{
    int a1, b1;
}p1[Max];

bool cmp(node1 x, node1 y)
{
    return x.a1 > y.a1;
}

int main()
{
    cin >> n;
    cin >> h;
    h *= 12;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].a;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].b;
    }
    for(int i = 2; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int k = h;
        int l = 0;
        for(int j = 1; j <= i; j++)
        {
            p1[j].a1 = p[j].a;
            p1[j].b1 = p[j].b;
            k -= c[j];
        }
        sort(p1 + 1, p1 + i + 1, cmp);
        while(p1[1].a1 > 0 && k > 0)
        {
            l += p1[1].a1;
            p1[1].a1 -= p1[1].b1;
            k--;
            sort(p1 + 1, p1 + i + 1, cmp);
        }
        m = max(m, l);
    }
    cout << m << endl;
    return 0;
}