#include <iostream>
using namespace std;

const int Max = 100010;
int t, n;
int ans[Max], sq[Max], ne[Max];

void create(int n)
{
    if(n == 0) return;
    int top = sq[ne[n - 1]];
    int last = top - n;
    for(int i = n - 1; i >= top - n; i--)
    {
        //cout << i << " " << n << ", " << top << ", ";
        ans[top - i] = i;
    }
    if(last < 0) return;
    create(last);
    //cout << last << ", " << endl;
}

int main()
{
    cin >> t;
    for(int i = 0; i * i <= Max; i++)
    {
        sq[i] = i * i;
        if(i == 0) ne[0] = 0;
        else
        {
            for(int j = sq[i - 1] + 1; j <= sq[i]; j++)
            {
                ne[j] = i;
            }
        }
    }
    while(t--)
    {
        cin >> n;
        if(n == 1) cout << "0" << endl;
        else if(n == 2) cout << "1 0" << endl;
        else if(n == 3) cout << "1 0 2" << endl;
        else if(n == 4) cout << "0 3 2 1" << endl;
        else
        {
            create(n);
            ans[1] += 1, ans[2] += 1;
            for(int i = 1; i <= n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}