#include <iostream>
using namespace std;

string s;

int main()
{
    cin >> s;
    int len = s.length();
    int ans = 0, left = 0, cnt = 0;
    while(cnt <= len - 1)
    {
        if(s[cnt] == '(')
        {
            left++;
        }
        if(s[cnt] == ')')
        {
            if(left == 0) 
            {
                ans++;
            }
            else
            {
                left--;
            }
        }
        cnt++;
    }
    cout << ans + left << endl;
    return 0;
}