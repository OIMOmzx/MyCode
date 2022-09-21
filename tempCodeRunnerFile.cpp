#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int n;
int a[Max], b[Max];
int sum1 = 0, sum2 = 0;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        sum1 += abs(a[i] - b[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        sum2 += abs(a[n - i + 1] - b[i]);
    }
    if(sum2 <= sum1 - 1)
    {
        cout << sum2 + 1 << endl;
    }
    else
    {
        cout << sum1 << endl;
    }
    return 0;
}