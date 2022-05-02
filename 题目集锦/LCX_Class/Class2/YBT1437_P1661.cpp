#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define Max 1000010
#define inf 0x3f3f3f3f
using namespace std;

int fa[Max], n;

struct node
{
    int x, y;
}a[Max];

class DSU
{
    public:
    int Find(int x)
    {
        if(fa[x] == x) return x;
        return Find(fa[x]);
    }
    
    void init()
    {
        for(int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }

    int getnum()//判断连通块的数量
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(fa[i] == i) cnt++;
        }
        return cnt;
    }

    void merge(int p, int q)
    {
        if(p != q)
        {
            fa[q] = p;
        }//将他们并入一个连通块
    }
};

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        //cout << "ejk" << endl;
    }
    int l = 0, r = inf;
    int ans = 0;
    DSU obj;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        //cout << mid << ": " << endl;
        obj.init();
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                //枚举，每次拿出两个点
                int dis = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
                if(dis <= mid * 2)//这两个点是否可以形成一个连通块
                {
                    int res1 = obj.Find(i), res2 = obj.Find(j);
                    obj.merge(res1, res2);
                }
            }
        }
        //cout << obj.getnum() << endl;
        if(obj.getnum() == 1)//可以在目前二分的时间，即 mid 内，形成一个连通块
        {
            r = mid;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}