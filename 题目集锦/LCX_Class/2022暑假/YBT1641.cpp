#include <iostream>
using namespace std;

const int Max = 210;
int n, m, p;
int a[Max][Max], b[Max][Max];
long long ans[Max][Max];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &p);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                ans[i][j] +=  a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}