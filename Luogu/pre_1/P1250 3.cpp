#include <iostream>
#include <algorithm>
using namespace std;

const long long Max = 1000010;
struct node
{
    long long first;
    long long second;
    long long num;
}a[Max];
long long len, n;
bool t[Max];

bool cmp(node x, node y)
{
    if(x.second < y.second) return 1;
    if(x.second == y.second && x.first < y.first) return 1;
    return 0;
}

int main()
{
    cin >> len >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second >> a[i].num;
    }
    sort(a + 1, a + n + 1, cmp);
    long long ans = 0;
    for(long long i = 1; i <= n; i++)
    {
        long long res = 0;
        for(long long j = a[i].first; j <= a[i].second; j++)
        {
            if(t[j]) res++;
        }
        if(res >= a[i].num) continue;
        for(long long j = a[i].second; j >= a[i].first; j--)
        {
            if(!t[j])
            {
                t[j] = 1;
                res++;
                ans++;
            }
            if(res == a[i].num)
            {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}