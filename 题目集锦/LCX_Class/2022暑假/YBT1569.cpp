#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
const int Max = 10000010;
int num[Max], sum[Max], n;
int Minn[8010][8010], Maxn[8010][8010];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) 
	{
		cin >> num[i];
		num[i + n] = num[i];
	}
    for(int i = 1; i <= 2 * n; ++i) 
    {
    	sum[i] = sum[i - 1] + num[i];
	    Minn[i][i] = 0, Maxn[i][i] = 0;
	}
    for(int L = 2; L <= n; ++L)
    {
        for(int i = 1; i <= 2 * n - L + 1; ++i)
        {
            int j = i + L - 1;
            Minn[i][j] = inf, Maxn[i][j] = -inf;
            for(int k = i; k < j; ++k)
            {

                Minn[i][j] = min(Minn[i][k] + Minn[k + 1][j], Minn[i][j]);
                Maxn[i][j] = max(Maxn[i][k] + Maxn[k + 1][j], Maxn[i][j]);
            }
            Minn[i][j] += (sum[j] - sum[i - 1]);
            Maxn[i][j] += (sum[j] - sum[i - 1]);
        }
    }
    int ans1 = inf, ans2 = -inf;
    for(int i = 1; i <= n; ++i)
    {
        ans1 = min(ans1, Minn[i][i + n - 1]);
        ans2 = max(ans2, Maxn[i][i + n - 1]);
    }
    cout << ans1 << endl << ans2;
    return 0;
}