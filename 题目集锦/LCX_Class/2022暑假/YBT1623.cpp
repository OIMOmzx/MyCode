#include <iostream>
using namespace std;

const int Max = 10000010;
int prime[Max];
bool vis[Max];
int cnt = 0;

int main()
{
    int n;
    cin >> n;
    if(n < 3) cout << "1" << endl;
    else cout << "2" << endl;
    for(int i = 2; i <= n + 1; i++)
    {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= n + 1; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) continue;
        }
    }
    for(int i = 2; i <= n + 1; i++)
    {
        if(!vis[i]) cout << "1 ";
        else cout << "2 ";
    }
    return 0;
}