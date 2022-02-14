#include <iostream>
using namespace std;

int w, t;
const int Max = 200000010;
int a[Max], res = 4, now;
unsigned long long cnt;
bool flag = 0, fl = 0;

int main()
{
    cin >> w >> t;
    cnt = w * w;
    a[1] = 1, a[2] = w - 1, a[3] = w, a[4] = w + 1;
    if(w == 1 && t <= 64) cout << "Yes" << endl;
    else if(w == 1 && t >= 65) cout << "No" << endl;
    else if(w == 2 || w == 3) cout << "Yes" << endl;
    else
    {
        while(1)
        {
            if(cnt >= Max) break;
            a[cnt] = 1;
            now = res;
            for(int i = 1; i <= now; i++)
            {
                if(cnt - a[i] > t) 
                {
                    fl = 1;
                }
                a[++res] = cnt - a[i];
                a[++res] = cnt + a[i];
            }
            if(fl) break;
            cnt *= w;
        }
        for(int i = 1; i <= res; i++)
        {
            if(a[i] == t) 
            {
                cout << "Yes" << endl, flag = 1;
                break;
            }
        }
        if(!flag) cout << "No" << endl;
    }
    /*
    for(int i = 1; i <= t; i++)
    {
        if((i % w == 1 && a[(i - 1) / w]) || (i % w == (w - 1) && a[(i + 1) / w]) || (i % w == 0 && a[i / w]))
        {
            a[i] = 1;
        }
    }
    //cout << a[0] << ' ' << a[1] << endl;
    if(a[t] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    if(w == 2) cout << "Yes" << endl;
    else
    {
        if(t % w == 1 || t % w == (w - 1) || t % w == 0)
        {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    */
    return 0;
}