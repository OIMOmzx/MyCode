#include <iostream>
using namespace std;

const int Max = 1000010;
int prime[Max];
bool vis[Max];

int main()
{
    int n, cnt = 0;
    for(int i = 2; i <= Max; i++)
    {
        if(vis[i] == 0) prime[cnt++] = i;
        for(int j = 0; j < cnt && i * prime[j] <= Max; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    while(cin >> n && n)
    {
        for(int i = 3; i <= n; i++)
        {
            if(!vis[i] && !vis[n - i])
            {
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
        }
    }
    return 0;
}