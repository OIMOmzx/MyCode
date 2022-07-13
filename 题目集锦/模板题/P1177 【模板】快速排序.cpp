#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000010], n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}