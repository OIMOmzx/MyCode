#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 10000010;
int a[Max], n, sum = 0, ans;
double aver, diff[Max], tar, res;

int main()
{
    cin >> n;
    for(int i =  1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    aver = sum * 1.0 / n;
    if(aver >= 90) cout << "0" << endl;
    else 
    {
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++)
        {
            sum += (100 - a[i]), ans++;
            if(sum * 1.0 / n >= 90) 
            {
                cout << ans << endl;
                break;
            }
            else continue;
        }
    }
    return 0;
}