#include <iostream>
using namespace std;

const int Max = 10000010;
int a[Max], n, ans = 0;
bool flag[Max];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[a[i]] == i && (!flag[a[i]] && !flag[i]))
        {
            flag[a[i]] = 1;
            flag[i] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}