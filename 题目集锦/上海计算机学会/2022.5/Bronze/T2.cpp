#include <iostream>
#include <cstring>
using namespace std;

const int Max = 100;
int ans1 = 0, ans2 = 0;
char s1[Max], s2[Max];
int a[Max], b[Max];

int main()
{
    cin >> (s1 + 1) >> (s2 + 1);
    for(int i = 1; i <= 4; i++)
    {
        a[s1[i] - '0']++;
        b[s2[i] - '0']++;
        if(s2[i] == s1[i]) ans1++;
    }
    for(int i = 0; i <= 9; i++)
    {
        if(a[i] != 0 && b[i] != 0 && a[i] == b[i])
        {
            ans2++;
        }
    }
    cout << ans1 << endl << ans2 - ans1;
    return 0;
}