#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int now[Max], want[Max];
int n, a[Max], b[Max], ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> now[i] >> want[i];
    }
    for(int i = 1 ; i<= n ; i++)
	{
		int res = want[i] - now[i];
		if(res >= 0) a[i] = res;
		else b[i] = -res;
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > a[i - 1]) ans += a[i] - a[i - 1]; 
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[i] > b[i - 1]) ans += b[i] - b[i - 1];
	}
	cout << ans;
    return 0;
}