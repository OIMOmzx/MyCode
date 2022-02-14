#include <iostream>
using namespace std;

const int mod = 1000003;
const int Max = 10000010;
int a[Max];
int t, x, res;
char type;
bool flag = 0;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> type >> x;
		if(type == 'I')
		{
			res = x % mod;
			while(1)
			{
				if(a[res] == 0)
				{
					a[res] = x;
					break;
				}
				else
				{
					res++;
					res %= mod;	
				}
			}
		}
		if(type == 'Q')
		{
			res = x % mod, flag = 0;
			while(a[res])
			{
				if(a[res] == x)
				{
					cout << "Yes" << endl;
					flag = 1;
					break;
				}
				else
				{
					res++;
					res %= mod;
				}
			}
			if(flag == 0) cout << "No" << endl;
		}
	 } 
	return 0;
}