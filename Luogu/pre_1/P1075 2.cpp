#include <iostream>
#include <cmath>
using namespace std;

long long n;

int main()
{
	cin >> n;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0) 
		{
			cout << n / i << endl;
			break;
		}
	}
	return 0;
}