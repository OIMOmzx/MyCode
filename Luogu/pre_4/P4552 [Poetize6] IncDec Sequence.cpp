#include <bits/stdc++.h>
using namespace std;
const int Max = 100010;

int n;
long long a[100010], diff[100010], res1, res2;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
	for(int i = 2; i <= n; i++)
    {
		diff[i] = a[i] - a[i - 1]; 
	}
    for(int i = 2; i <= n; i++)
    {
        if(diff[i] < 0) 
        {
            res1 -= diff[i];
        }
        else
        {
            res2 += diff[i];
        }
    }
	cout << max(res1, res2) << endl << abs(res1 - res2) + 1;
	return 0;
}
