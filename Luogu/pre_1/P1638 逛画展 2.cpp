#include<bits/stdc++.h>
using namespace std;

const int Max = 1000010;
int n, m;
int a[Max], b[Max];
int res = 1, ans = INT_MAX, l = 1, r = 1, ansl, ansr;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    b[a[1]] = 1;
	while(l <= r && r <= n)
	{
		if(res == m)
		{
			if(ans > r - l + 1)	
			{
				ans = r - l + 1;
				ansl = l, ansr = r;
			}
			b[a[l]]--;
			if(b[a[l]] == 0) res--;
			l++;
		}
		else
        {
			r++;
			b[a[r]]++;
			if(b[a[r]] == 1) res++;
		}
	}
	cout << ansl << " " << ansr << endl;
	return 0;
}
