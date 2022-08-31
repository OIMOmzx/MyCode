#include <iostream>
#include <algorithm>
#define Max 1000010
#define inf 0x3f3f3f3f
using namespace std;

int n, m;
int s[Max], v[Max];
int ans = inf;

void dfs(int now_v, int now_s, int left, int r, int h)
{
    int h_res = inf;
    if(left == 0)
    {
        if(now_v == n)
        {
            ans = min(ans, now_s);
        }
        return;
    }
    if(now_s + s[left - 1] > ans || now_v + v[left - 1] > n) return;
    if(2 * (n - now_v) / r + now_s >= ans) return;
    for(int i = r - 1; i >= left; i--)
    {
        if(left == m) now_s = i * i;
        h_res = min((n - now_v - v[left - 1]) / (i * i), h - 1);
        for(int j = h_res; j >= left; j--)
        {
            dfs(now_v + i * i * j, now_s + 2 * i * j, left - 1, i, j);
        }
	}
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        v[i] = v[i - 1] + i * i * i;
        s[i] = s[i - 1] + 2 * i * i;
    }
    dfs(0, 0, m, n, n);
    if(ans == inf)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}