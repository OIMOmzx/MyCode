#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
bool a[100];
char s[300010];

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> (s + 1);
        int res = 0, cnt = 0;
        for(int i = 1; i <= strlen(s + 1); i++)
        {     
            if(a[s[i] - 'a' + 1] == 1)
            {
                continue;
            }
            if(a[s[i] - 'a' + 1] == 0)
            {
                if(cnt == 3)
                {
                    //cout << "i" << i << ", ";
                    res++;
                    cnt = 0;
                    memset(a, 0, sizeof(a));
                }
                cnt++;
                a[s[i] - 'a' + 1] = 1;
            }
            //cout << cnt << ", " <<  res << endl;
        }
        cout << res + 1 << endl;
        cnt = 0, res = 0, memset(a, 0, sizeof(a));
    }
    return 0;
}