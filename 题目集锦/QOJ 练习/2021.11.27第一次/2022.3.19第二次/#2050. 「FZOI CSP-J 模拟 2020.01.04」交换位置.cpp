#include <iostream>
using namespace std;

const int Max = 110;
int n, res[Max], a[Max];
int b[Max], c[Max], d[Max];
int order[Max];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> res[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        order[res[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        b[order[i]] = a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        c[order[i]] = b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        d[order[i]] = c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << endl;
    }
    return 0;
}