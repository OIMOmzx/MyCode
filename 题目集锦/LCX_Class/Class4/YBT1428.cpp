#include <iostream>
#define Max 1000010
using namespace std;

int n, num;
int a[Max];
int ans, i, res = 0;

int main()
{
    cin >> n >> num;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    i = 1;
    while(i <= n)
    {
        while(res + a[i] <= num)
        {
            res += a[i];
            i++;
        }
        if(res + a[i] > num) ans++, res = 0;
    }
    cout << ans << endl;
    return 0;
}