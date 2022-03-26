#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
const int Max = 1010;
int t, len1, len2;
string s1, s2;
int ans = 0;

void dfs(int step, string res, int cnt1, int cnt2)
{
    if(step == len1 - 1)
    {
        if(res == s2) ans++;
        return;
    }
    else if(s1[step] == '-')
    {
        dfs(step + 1, res, cnt1 - 1, cnt2);
        dfs(step + 1, res, cnt1, cnt2 - 1);
    }
    else
    {
        res[cnt2 + 1] = s1[step];
        dfs(step + 1, res, cnt1, cnt2 + 1);
    }
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> len1 >> len2;
        for(int i = 0; i < len1; i++)
        {
            cin >> s1[i];
        }
        for(int i = 0; i < len2; i++)
        {
            cin >> s2[i];
        }
        dfs(0, "", 0, 0);
        cout << ans << endl;
    }
    return 0;
}