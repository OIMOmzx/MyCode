#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
long long t, x, y;
long long a[Max];

void solve(long long n)
{
    if(n == 0) 
    {
        cout << "0" << endl;
        return;
    }
    int cnt = 1;
    while(n >= 1)
    {
        a[cnt++] = n % 2;
        n /= 2;
    }
    for(int i = cnt - 1; i >= 1; i--)
    {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    cin >> t;
    for(long long i = 1; i <= t; i++)
    {
        cin >> x >> y;
        solve(x * 5 + y);
    }
    return 0;
}