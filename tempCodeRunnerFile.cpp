#include <iostream>
#include <cstring>
using namespace std;

int n, m, y, x;
char a[1010];
int mp[51][51];
int now[51][51];

int main()
{
    cin >> n >> m >> y >> x;
    cin >> (a + 1);
    int len = strlen(a + 1);
    for(int i = 1; i <= len; i++)
    {
        if(i >= 2)
        {
            if(a[i - 1] == 'N')
            {
                x += 1;
            }
            if(a[i - 1] == 'S')
            {
                x -= 1;
            }
            if(a[i - 1] == 'W')
            {
                y -= 1;
            }
            if(a[i - 1] == 'E')
            {
                y += 1;  
            }
        }
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                now[j][k]++;
            }
        }

        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(j == x && k == y)
                {
                    now[j][k] = 0;
                    continue;
                }
                else
                {
                    mp[j][k] += now[j][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << mp[n - i + 1][j] << " ";
        }
        cout << endl;
    }
    return 0;
}