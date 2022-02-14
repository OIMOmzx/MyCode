#include <bits/stdc++.h>
using namespace std;

int a[20][20];
int n, m, p, q;
bool flag1 = 0, flag2 = 0;

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        cin >> p >> q;
        a[p][q] = 1;   
    }
    if(n == 1) cout << "1" << endl;
    else if(n == 2)
    {
        if(m == 0) cout << "2" << endl;
        if(m == 1) cout << "1" << endl;
    }
    else if(n == 3)
    {
        if(m == 0) cout << "3" << endl;
        if(m == 1) cout << "2" << endl;
        if(m == 2) cout << "2" << endl;
        if(m == 3) cout << "1" << endl;
    }
    else
    {
        if(m == 0) cout << n << endl;
        if(m == 1) cout << n - 1 << endl;
        int res = 0;
        for(int i = 1; i <= 19; i++)
        {
            for(int j = 1; j <= 19; j++)
            {
                if(a[i][j] == 1) res++;
            }
            if(res == 2)
            {
                flag1 = 1;
                break;
            }
        }
        res = 0;
        for(int i = 1; i <= 19; i++)
        {
            for(int j = 1; j <= 19; j++)
            {
                if(a[j][i] == 1) res++;
            }
            if(res == 2)
            {
                flag2 = 1;
                break;
            }
        }
        if(m == 2)
        {
            if(flag1 == 1 || flag2 == 1)
            {
                cout << n - 1 << endl;
            }
            else cout << n - 2 << endl;
        }
        if(m == 3)
        {
            cout << n - 2 << endl;
        }
    }
    return 0;
}