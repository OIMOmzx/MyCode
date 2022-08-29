#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 1000010;
int n, c, a[Max];

bool check(int x) 
{
	int res = 1, last = a[1];
	for(int i = 2; i <= n; i++) 
    {
		if(a[i] - last > x) last = a[i], res++;
	}
	return res >= c;
}

int main()
{
    cin >> n >> c;
    for(int i = 1; i <=  n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = a[n] - a[1];
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}