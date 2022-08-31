#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
char a[3], b[3];
bool num[27];

int main()
{
    cin >> t;
    while(t--)
    {
        for(int i = 0; i <= 26; i++)
        {
            num[i] = 0;
        }
        cin >> (a + 1) >> (b + 1);
        num[a[1] - 'a' + 1] = 1, num[b[1] - 'a' + 1] = 1, num[a[2] - 'a' + 1] = 1, num[b[2] - 'a' + 1] = 1;
        int ans = 0;
        for(int i = 1; i <= 26; i++)
        {
            if(num[i]) ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}