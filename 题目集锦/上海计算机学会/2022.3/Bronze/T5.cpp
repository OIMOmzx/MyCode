#include <iostream>
using namespace std;

const int Max = 10000010;
int n, k;
int a[2][Max];
int f[Max];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        a[0][i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }
    for(int j = 1; j <= k; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            a[j % 2][f[i]] = a[(j + 1) % 2][i];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[k % 2][i] << " ";
    }
    return 0;
}