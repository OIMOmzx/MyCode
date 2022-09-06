#include <iostream>
using namespace std;

int n, k, a[10], ans = 0;
void dfs(int step)
{
    if(n == 0) return;
    if(step == k)
    {
        if(n >= a[step - 1]) ans++;
        return;
    }
    for(int i = a[step - 1]; i <= n / (k - step + 1); i++)//上下界剪枝
    {
        a[step] = i;
        n = n - i;
        dfs(step + 1);
        n = n + i;
    }
}

int main()
{
    cin >> n >> k;
    a[0] = 1;
    dfs(1);
    cout << ans << endl;
    return 0;
}