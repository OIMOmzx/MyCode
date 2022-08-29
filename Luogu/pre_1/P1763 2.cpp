#include <iostream>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;
long long num[Max], tot[Max];
long long lim, ans;
long long a, b;
bool flag;

void dfs(long long dep, long long mol, long long den, long long pre)
{
    if(dep == lim + 1)
    {
        if(mol == 0)
        {
            flag = 1;
            if(num[lim] < tot[lim])
            {
                for(int i = 1; i <= lim; i++)
                {
                    tot[i] = num[i];
                }
                ans = num[lim];
            }
        }
        return;
    }
    if(den * (lim + 1 - dep) / mol > ans || num[lim] > ans)
    {
        return;
    }
    for(int i = max(pre, den / mol); i <= den * (lim + 1 - dep) / mol; i++)
    {
        num[dep] = i;
        dfs(dep + 1, mol * i - den, den * i, i + 1);
    }
}

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    cin >> a >> b;
    for(lim = 1; ;lim++)
    {
        tot[lim] = inf;
        ans = inf;
        dfs(1, a, b, 1);
        if(flag) break;
    }
    for(int i = 1; i <= lim; i++)
    {
        cout << tot[i] << " ";
    }
    return 0;
}