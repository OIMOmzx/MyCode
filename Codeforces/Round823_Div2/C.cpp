#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int Max = 1000010;
int n;
char s[Max];
int a[Max];
int vis[11];
int first[11];

int main()
{
    cin >> n;
    while(n--)
    {
        //cout << "rfjq3nrjfn3ojr";
        memset(vis, 0, sizeof(vis));
        cin >> (s + 1);
        int last, pos, minn = 114514;
        for(int i = 1; i <= strlen(s + 1); i++)
        {
            //cout << s[i];
            a[i] = s[i] - '0';
            //cout << a[i] << ", ";
            vis[a[i]]++;
            if(!first[a[i]]) first[a[i]] = i;
        }
        for(int i = 1; i <= strlen(s + 1); i++)
        {
            //cout << a[i];
            if(a[i] < minn)
            {
                minn = a[i];
                pos = i;
            }
        }
        last = minn;
        int last_pos, last_num = 0;
        for(int i = pos; i <= strlen(s + 1); i++)
        {
            if(a[i] == last)
            {
                cout << a[i];
                last_num += 1;
            }
            if(last_num == vis[last])
            {
                last_num = 0;
                last = a[i] + 1;
                while(vis[last] == 0 && last <= 9)
                {
                    last++;
                }
            }
        }
        for(int i = last; i <= 9; i++)
        {
            for(int j = 1; j <= vis[i]; j++)
            {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}