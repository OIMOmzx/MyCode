#include <iostream>
using namespace std;

const int Max = 10000010;
int num[Max];
int n, m, p[Max], q[Max];
bool flag;

int main()
{
    memset(num, 0x3f3f3f3f, sizeof(num));
    num[1] = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> p[i] >> q[i];
    }
    for(int j = 1; j <= n - 1; j++)
    {
        flag = 1;
        for(int i = 1; i <= m; i++)
        {
            if(num[q[i]] > num[p[i]] + 1) num[q[i]] = num[p[i]] + 1, flag = 0;  
            if(num[p[i]] > num[q[i]] + 1) num[p[i]] = num[q[i]] + 1, flag = 0;
        }
        if(flag == 1) break;
    }
    int ans1 = 0, ans2 = -INT_MAX, ans3 = 0;
    for(int i = 1; i <= n; i++)
    {
        //cout << num[i] << ',';
        if(num[i] > ans2) ans1 = i, ans2 = num[i], ans3 = 1;
        else if(num[i] == ans2) ans3++;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}