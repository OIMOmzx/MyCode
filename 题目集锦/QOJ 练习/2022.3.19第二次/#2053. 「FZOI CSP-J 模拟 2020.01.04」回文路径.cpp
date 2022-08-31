#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int n;
char a[21][21];
int cnt = 1;
bool flag = 1;
int ans = 0;
set<string> res;

void dfs(int l, int r, string s)
{
    if(l == n && r == n)
    {
        s += a[l][r];
        //cout << s << endl;
        cnt = s.length();
        flag = 1;
        for(int i = 0; i <= cnt / 2 - 1; i++)
        {
            if(s[i] != s[cnt - i - 1]) flag = 0;
        }
        if(flag == 1)
        {
            /*
            cout << "yee" << endl;
            cout << cnt << endl;
            for(int i = 1; i <= cnt; i++)
            {
                cout << res[i];
            }
            cout << endl;
            */
            res.insert(s);
        }
        flag = 1, cnt = 0;
        return;
    }
    //res[cnt++] = a[l][r];
    //cout << l << ',' << r << endl;
    //cout << cnt - 1 << ":" << res[cnt - 1] << endl;
    if(l + 1 <= n) dfs(l + 1, r, s + a[l][r]);
    if(r + 1 <= n) dfs(l, r + 1, s + a[l][r]);
    return;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(1, 1, "");
    cout << res.size() << endl;
    return 0;
}