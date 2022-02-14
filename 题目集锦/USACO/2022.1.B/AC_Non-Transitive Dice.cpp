#include <iostream>
#include <algorithm>
using namespace std;

int a[4][5], t;
bool flag = 0;

bool isvalid(int n)
{
    int res = 0, cnt = 0;
    int t1 = n, t2 = n + 1;
    if(t2 == 4) t2 %= 3;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            if(a[t1][i] > a[t2][j]) res++;
            if(a[t1][i] == a[t2][j]) cnt++;
        }
    }
    //cout << res << ", " << cnt << endl;
    if(res * 2 > 16 - cnt) return 1;
    return 0;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        flag = 0;
        cin >> a[1][1] >> a[1][2] >> a[1][3] >> a[1][4];
        cin >> a[2][1] >> a[2][2] >> a[2][3] >> a[2][4];
        for(int j1 = 1; j1 <= 10; j1++)
        {
            for(int j2 = 1; j2 <= 10; j2++)
            {
                for(int j3 = 1; j3 <= 10; j3++)
                {
                    for(int j4 = 1; j4 <= 10; j4++)
                    {
                        a[3][1] = j1, a[3][2] = j2, a[3][3] = j3, a[3][4] = j4;
                        if(isvalid(1) && isvalid(2) && isvalid(3) && flag == 0)
                        {
                            //cout << j1 << ", " << j2 << ", " << j3 << ", " << j4;
                            cout << "yes" << endl;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        //cout << flag ;
        if(flag == 0) cout << "no" << endl;
    }
    return 0;
}