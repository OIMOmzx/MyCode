#include <iostream>
using namespace std;

const int Max = 1000010;
int a[Max], t, n;

int main()
{
    cin >> t;
    while(t--)
    {
        bool flag = 1;
        int cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(i == 2)
            {
                cnt = a[i] - a[i - 1];
            }
            else if(i >= 3)
            {
                if(a[i] - a[i - 1] != cnt)
                {
                    flag = 0;
                }
            }
            else if(a[i] < a[i - 1])
            {
                flag = 0;
            }
        }
        //cout << flag << endl;
        if(!flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}