#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int Max = 10000010;
int a[Max], t[Max], cost[Max], n;

int main()
{
    memset(cost, -0x3f3f3f3f, sizeof(cost));
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> t[i];
    }
    cost[1] = a[1];
    cost[t[1]] = a[1] + a[t[1]];
    for(int i = 2; i <= n; i++)
    {
        //cout << cost[i] << ", " << a[i] + cost[i - 1] << endl;
        cost[i] = max(cost[i], a[i] + cost[i - 1]);
        cost[t[i]] = max(cost[t[i]], cost[i] + a[t[i]]);
    }
    cout << cost[n];
    return 0;
}