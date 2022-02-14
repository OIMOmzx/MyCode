#include <iostream>
using namespace std;

int a[30];
int ans[10000010];

int main()
{
    int cnt = 1, res = 1, x, n, i = 1;
    cin >> n;
    while(i++)
    {
        res = 1;
        x = i;
        while(x >= 1)
        {
            a[res++] = x % 10;
            x /= 10;
        }
        for(int j = 3; j <= res - 1; j++)
        {
            if(a[j - 2] == 6 && a[j - 1] == 6 && a[j] == 6) 
            {
                //ans[cnt++] = i;
                //cout << i << ", ";
                cnt++;
                if(cnt - 1 == n) 
                {
                    cout << i << endl;
                    break;
                }
                break;
            }
        }
    }
    return 0;
}