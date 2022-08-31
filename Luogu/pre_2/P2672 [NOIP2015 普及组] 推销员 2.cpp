#include <iostream>
#include <algorithm>
using namespace std;
int n, sum[10000010], remain[10000010], rechange[10000010];
struct node
{
    int a;
    int s;
}m[10000010];
bool cmp(node x,node y)
{
    return x.a > y.a;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> m[i].s;
    for(int i = 0; i < n; i++) cin >> m[i].a;
    sort(m, m + n, cmp);
    for(int i = 0; i < n; i++) sum[i] = sum[i - 1] + m[i].a;
    for(int i = 0; i < n; i++) remain[i] = max(remain[i - 1], 2 * m[i].s);
    for(int i = n - 1; i >= 0; i--) rechange[i] = max(rechange[i + 1], 2 * m[i].s + m[i]. a);
    for(int i = 0; i < n; i++) cout << max(sum[i] + remain[i], sum[i - 1] + rechange[i]) << endl;
    return 0;
}