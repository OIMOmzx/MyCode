#include <iostream>
#include <vector>
using namespace std;

int t, a[5], b, c, d;
int num[20];

int main()
{
    //freopen("one2.in", "r", stdin);
    //freopen("one2.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        int flag = 0, fl = 0;
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= 4; i++)
        {
            cin >> a[i];
            num[a[i]]++;
            if(num[a[i]] == 2) flag++;
            if(num[a[i]] == 3)
            {
                flag = 3;
            }
            if(num[a[i]] == 4)
            {
                flag = 2;
            }
        }
        sort(a + 1, a + 4 + 1);
        //cout << flag << endl;
        if(flag == 0)
        {
            bool p = 0;
            for(int i = 1; i <= 2; i++)
            {
                if(a[i] == a[i + 1] - 1 && a[i] == a[i + 2] - 2) 
                {
                    cout << "1" << endl, p = 1;
                    break;
                }
            }
            if(!p) cout << "0" << endl;
        }
        if(flag == 1)
        {
            vector<int> res;
            for(int i = 1; i <= 4; i++)
            {
                if(num[a[i]] == 1) res.push_back(a[i]);
            }
            if(res[1] - res[0] <= 2) cout << "1" << endl;
            else cout << "0" << endl;
        }
        if(flag == 2)
        {
            cout << "0" << endl;
        }
        if(flag == 3)
        {
            if(a[2] - a[1] + a[4] - a[3] <= 2) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }
    return 0;
}