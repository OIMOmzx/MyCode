#include <iostream>
using namespace std;
unsigned long long t, n;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n % 2) cout << n * (n - 1) / 2 << endl;
		else cout << (n * (n - 2) + 2) / 2<<endl;
	}
    return 0;
}