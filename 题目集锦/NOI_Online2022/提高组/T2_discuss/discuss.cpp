#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int Max = 8010;
int t, n, k, res;
vector<vector<int> > a;
int to[Max];

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

int count(int x, int y)
{
    int res = 0;
    for(int i = 1; i <= a[x].size(); i++)
    {
        if(a[x][i] == y) res++;
    }
    return res;
}

bool is_valid(int x, int y)
{
    int tmp1 = 1, tmp2 = 1;
    while(tmp1 <= a[x].size() && tmp2 <= a[x].size())
    {
        while(a[x][tmp1] == a[y][tmp2])
        {
            tmp1++;
            tmp2++;
        }
        if(a[x][tmp1] != a[y][tmp2])
        {
            tmp2++;
        }
    }
    if(tmp1 == a[x].size()) return 0;
    return 1;
}

int main()
{
    freopen("discuss.in", "r", stdin);
    freopen("discuss.out", "w", stdout);
    t = read();
    for(int i = 1; i <= t; i++)
    {
        bool flag = 0;
        n = read();
        for(int j = 1; j <= n; j++)
        {
            k = read();
            vector<int> tmp;
            if(k != 0)
            {
                tmp.push_back(0);
                for(int p = 1; p <= k; p++)
                {
                    res = read();
                    tmp.push_back(res);
                    to[res]++;
                }
                sort(tmp.begin(), tmp.end());
                a.push_back(tmp);
            }
            else
            {
                tmp.push_back(0);
                a.push_back(tmp);
            }
            tmp.clear();
        }
        
        for(int j = 0; j < n; j++)
        {
            for(int p = j + 1; p < n; p++)
            {
                for(int q = 1; q <= n; q++)
                {
                    int cnt1, cnt2;
                    if(a[j].size() <= a[p].size()) cnt1 = j, cnt2 = p;
                    else cnt1 = p, cnt2 = j;
                    if(count(j, q) != 0 && count(p, q) != 0 && is_valid(cnt1, cnt2))
                    {
                        //cout << cnt1 << ", " << cnt2 << endl;
                        //cout << a[j].size() << ", " << a[p].size();
                        //cout << count(j, q) << ", " << count(p, q) << endl;
                        //cout << q << endl;
                        cout << "YES" << endl;
                        cout << j + 1 << " " << p + 1 << endl;
                        flag = 1;
                        break;
                    }
                    
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
        }
        if(flag == 0) cout << "NO" << endl;
        a.clear();
        for(int i = 1; i <= n; i++)
        {
            to[i] = 0;
        }
    }
    return 0;
}