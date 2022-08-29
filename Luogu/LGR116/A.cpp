#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    char a[20];
    cin >> t;
    while(t--)
    {
        bool flag = 0;
        cin >> (a + 1);
        int len = strlen(a + 1);
        if(a[1] == 'D' && a[2] == 'X') cout << "Yes" << endl, flag = 1;
        else
        {
            for(int i = 1; i <= len - 3; i++)
            {
                if(a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3])
                {
                    cout << "Yes" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) cout << "No" << endl;
    }
    return 0;
}