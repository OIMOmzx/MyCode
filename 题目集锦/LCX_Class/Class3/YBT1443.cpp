//吃了半个直径为 13.2cm 的黄色西瓜
//tnnd，用了 42 分钟
#include <iostream>
#include <cstring>
#define inf 54188
#define Max 1000010
using namespace std;

int n, a[Max], ans[Max];
int minn;
bool flag = 0;

int work(int x)
{
    int cnt = 0, res = 1;
    while(res < x)
    {
        res *= 2;
        cnt++;
    }
    return cnt;
}

void dfs(int x)
{
    if(x >= minn) return;
    if(a[x] > n) return;
    if(a[x] == n)
    {
        minn = x;
        for(register int i = x; i >= 1; i--) 
        {
            ans[i] = a[i];
        }
        return;
    }
    else
    {
        for(int i = x; i >= 1; i--)
        {
            for(int j = x; j >= i; j--)
            {
                if(a[i] + a[j] <= n && a[i] + a[j] > a[x])
                {
                    a[x + 1] = a[i] + a[j];
                    /*
                    int res = a[x + 1];
                    for(int k = x + 2; k <= minn; k++)
                    {
                        res *= 2;
                    }
                    if(res < n) continue;
                    */
                    dfs(x + 1);
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    while(n)
    {
        if(n == 0) break;
        a[1] = 1, a[2] = 2;
        minn = inf;
        dfs(1);
        for(int i = 1; i <= minn; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}