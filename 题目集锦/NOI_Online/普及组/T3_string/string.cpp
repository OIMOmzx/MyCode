#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
const int Max = 1010;
int t, len1, len2;
char s1[Max], s2[Max], res[Max];
int ans = 0;

void dfs(int step, char res[Max], int cnt1, int cnt2)
{
    bool flag = 1;
    if(step == len1)
    {    
        if(s1[step] == '-')
        {
            for(int i = cnt1 + 1; i <= cnt2; i++)
            {
                //cout << res[i] << s2[i - cnt1] << ", ";
                if(res[i] != s2[i - cnt1]) flag = 0;
            }
            if(flag == 1) ans++;
            for(int i = cnt1; i <= cnt2 - 1; i++)
            {
                //cout << res[i] << s2[i - cnt1] << ", ";
                if(res[i] != s2[i - cnt1]) flag = 0;
            }
            if(flag == 1) ans++;
        }
        else
        {
            res[cnt2] = s1[step];
            for(int i = cnt1; i <= cnt2; i++)
            {
                //cout << res[i] << s2[i - cnt1] << ", ";
                if(res[i] != s2[i - cnt1]) flag = 0;
            }
            if(flag == 1) ans++;
        }
        return;
    }
    else if(s1[step] == '-')
    {
        dfs(step + 1, res, cnt1 + 1, cnt2);
        dfs(step + 1, res, cnt1, cnt2 - 1);
    }
    else
    {
        //cout << step << ",  ";
        res[cnt2] = s1[step];
        //cout << 'e' << strlen(res) << endl;
        /*
        for(int i = cnt1; i <= cnt2; i++)
        {
            cout << res[i] << ", ";
        }
        */
        //cout << endl;
        dfs(step + 1, res, cnt1, cnt2 + 1);
    }
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> len1 >> len2;
        cin >> s1 >> s2;
        //cout << s2[0] << ", ";
        dfs(0, res, 0, 0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}