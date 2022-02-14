#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int Max = 1000010;
int n, a[Max], tree[Max];// sum[Max];
int p, q, t, num = 1;
string type;

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}

int lowbit(int x)
{
    return (-x) & x;
}

void update(int i, int v)
{
    for( ; i <= n; i += lowbit(i))
    {
        tree[i] += v;
    }
}

int rsum(int i)//求前缀和 a[1]...a[i]
{
    int res = 0;
    for( ; i > 0; i -= lowbit(i))
    {
        res += tree[i];
    }
    return res;
}

int sum(int i, int j)//求区间和 a[i]...a[j]
{
    return rsum(j) - rsum(i - 1);
}

int getValue(int idx)
{
    int ans = tree[idx];
    int lca = idx - lowbit(idx);//直接前驱
    idx--;
    while(idx != lca)
    {
        ans = ans - tree[idx];
        idx -= lowbit(idx);
    }
}

int main()
{
    t = read();
    while(t--)
    {
        memset(a, 0, sizeof(a)); 
        memset(tree, 0, sizeof(tree));
        n = read();
        for(int i = 1; i <= n; i++)
        {
            a[i] = read();
            update(i, a[i]);
        }
        cout << "Case " << num << ":" << endl;
        while(cin >> type)
        {
            if(type == "Query")
            {
                p = read(), q = read();
                cout << sum(p, q) << endl;
            }
            if(type == "update")
            {
                p = read(), q = read();
                a[p] += q;
                update(p, q);
            }
            if(type == "Sub")
            {
                p = read(), q = read();
                q = -q;
                a[p] += q;
                update(p, q);
            }
            if(type == "End")
            {
                num++;
                break;
            }
        }
    }
}