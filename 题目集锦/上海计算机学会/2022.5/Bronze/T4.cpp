#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int n;
struct node
{
    int x, y;
}a[Max];
int p[10][Max];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        p[0][i] = a[i].x + a[i].y;
  		p[1][i] = -a[i].x + a[i].y;
  		p[2][i] = a[i].x - a[i].y;
  		p[3][i] = -a[i].x - a[i].y;
    }
    for(int i = 0; i <= 3; i++)
    {
        sort(p[i] + 1, p[i] + n + 1);
    }
    int maxn = -0x3f3f3f3f;
    for(int i = 0; i <= 3; i++)
    {
        maxn = max(maxn, p[i][n] - p[i][1]);
    }
    cout << maxn << endl;
    return 0;
}