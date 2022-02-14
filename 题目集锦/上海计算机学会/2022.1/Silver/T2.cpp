#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 10000010;
int n, a[Max], ans, res;
bool flag = 0;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    /*
    for(int i = 1; i <= n; i++)
    {
        if(a[i] * 2 >= a[n])
        {
            res = i;
            break;
        }
    }
    */
    res = n / 2;
    for(int i = 1; i <= res; i++)
    {
        flag = 0;
        for(int j = res + 1; j <= n; j++)
        {
            if(a[j] >= a[i] * 2)
            {
                //cout << a[j] << ", ";
                a[j] = 0;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        //cout << a[i] << endl;
        if(a[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}