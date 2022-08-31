#include <iostream>
#include <cstring>
using namespace std;

const int Max = 100010;
int a[Max];
int t, n;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        int time = -0x3f3f3f3f;
        int res = 0;

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            time = max(time, a[i]);
            if(a[i] > a[i - 1]) res += a[i] - a[i - 1];
        }
        //cout << res << endl;
        if(time < res) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}