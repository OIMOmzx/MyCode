#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iomanip>
#define Max 10010
using namespace std;

long long a[Max];
bool used[Max];
long long minn = -0x3f3f3f3f, sum = 0;
long long len, m, n;
bool flag = 0;

void dfs(long long k, long long last, long long rest)
{
    if(k == m)
    {
        flag = 1;
        cout << len << endl;
        exit(0);
    }

    if(rest == 0)
    {
        for(long long i = 1; i <= n; i++)
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                dfs(k + 1, i, len - a[i]);
                used[i] = 0;
                break;
            }
        }
    }

    for(long long i = last + 1; i <= n; i++)
    {
        if(used[i] == 0 && rest >= a[i])
        {
            used[i] = 1;
            dfs(k, i, rest - a[i]);
            used[i] = 0;
            if(rest == a[i] || rest == len) return;
            while(a[i] == a[i + 1])
            {
                i++;
            }
            if(i == n) return;
        }
    }
}

bool cmp(long long x, long long y)
{
    return x > y;
}

int main()
{
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if(a[i] > 50) a[i] = 0;
        minn = max(minn, a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1, cmp);

    for(long long i = minn; i <= sum / 2 + 1; i++)
    {
        if(sum % i == 0)
        {
            memset(used, 0, sizeof(used));
            len = i, m = sum / i;
            used[1] = 1;
            dfs(1, 1, len - a[1]);
        }
    }
    if(flag == 0)
    {
        cout << sum << endl;
    }
    return 0;
}