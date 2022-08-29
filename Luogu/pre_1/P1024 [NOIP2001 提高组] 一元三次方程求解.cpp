#include <iostream>
#include <iomanip>
using namespace std;

double n, t, k;
double l, r, mid;
double a, b, c, d;
double ans1, ans2;

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
	cin >> a >> b >> c >> d;
	for(double x = -100; x <= 100; x++)
	{
		l = x, r = x + 1;
		if(f(l) == 0) cout << fixed << setprecision(2) << l << " ";
		if(f(l) * f(r) < 0)
		{
			while(l + 1e-6 <= r)
			{
				mid = (l + r) / 2;
				if(f(l) * f(mid) < 0) r = mid;
				else l = mid;
			}
			cout << fixed << setprecision(2) << l << " ";
		}
	}
	return 0;
}