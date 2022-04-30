#include <iostream>
#include <utility>
using namespace std;

const int Max = 10000010;
pair<int, int> a[Max];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a + 1, a + n + 1);
    int res1 = a[1].second, res2 = a[1].first;
    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
        //cout << a[i].first << endl;
        if(a[i].second >= res2)
        {
            res1 = a[i].second;
            res2 = a[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
