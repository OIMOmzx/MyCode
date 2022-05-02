#include <iostream>
using namespace std;

const int Max = 1010;
int n, m;
int a[Max][Max], tar[Max], my[Max];
int x, y, ans;

int main()
{
    freopen("kingdom.in", "r", stdin);
    freopen("kingdom.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= n; j++)
    {
        x = 0, y = 0;
        for(int i = 1; i <= m; i++)
        {
            if(a[i][j] == 1) x++;
            else y++;
        }
        if(x > y)  my[j] = 1;
        else my[j] = 0; 
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> tar[i];
        if(tar[i] == my[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}