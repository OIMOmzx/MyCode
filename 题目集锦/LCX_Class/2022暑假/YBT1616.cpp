#include <iostream>
using namespace std;

long long t, a, b, c, k;

long long m(long long res, long long time)
{
	long long sum = 1;
	while(time)
	{
		if(time % 2 == 1)
		{
			sum = sum * res % 200907;
		}
		time /= 2;
		res = res * res % 200907;
	}
	return sum % 200907;
}

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c >> k;
		if(2 * b == a + c)
		{
			int res = (b - a) % 200907;
			cout << (a + (k - 1) * res) % 200907 << endl;
		}
		else
		{
			cout << (a * m(b / a, k - 1)) % 200907 << endl;
		}
	}
	return 0;
}