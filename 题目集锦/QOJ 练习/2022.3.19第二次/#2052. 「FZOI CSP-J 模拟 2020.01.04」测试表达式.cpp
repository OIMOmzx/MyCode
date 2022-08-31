#include <iostream>
#include <vector>
using namespace std;

const int Max = 1010;
char ch;
int n, res;
int a[27][Max];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> ch >> res;
        a[ch - 'A' + 1][abs(res % 2)]++;
    }
    int ans = 0;
    for(int b = 0; b <= 1; b++)
    {
        for(int e = 0; e <= 1; e++)
        {
            for(int s = 0; s <= 1; s++)
            {
                for(int i = 0; i <= 1; i++)
                {
                    for(int g = 0; g <= 1; g++)
                    {
                        for(int o = 0; o <= 1; o++)
                        {
                            for(int m = 0; m <= 1; m++)
                            {
                                if(((b + e + s + s + i + e) * (g + o + e + s) * (m + o + o)) % 2 == 0)
                                {
                                    ans += a['B' - 'A' + 1][b] * a['E' - 'A' + 1][e] * a['S' - 'A' + 1][s] * a['I' - 'A' + 1][i] * a['G' - 'A' + 1][g] * a['O' - 'A' + 1][o] * a['M' - 'A' + 1][m];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}