#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[4];
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 3 + 1);
    for(int i = 1; i <= 3; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}