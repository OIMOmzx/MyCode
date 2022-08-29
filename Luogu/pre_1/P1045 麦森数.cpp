#include <iostream>
#include <cmath>
using namespace std;

unsigned long long pow(int n, int time)
{
	if(time == 0) return 1;
	if(time == 1) return n;
	else return pow(n, time - 1) * n;
}

unsigned long long a[501];

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}

int main()
{
	unsigned long long  t32 = pow(2, 32);
	int p; p = read();
	a[500] = 1;
	int can = p / 32, left = p - can * 32;
	for(int i = 1; i <= can; i++)
	{
		for(int i = 500; i >= 1; i--)
		{
			a[i] *= t32;
		}
		for(int i = 500; i >= 1; i--)
		{
			a[i - 1] += a[i] / 10;
			a[i] = a[i] % 10;
		}
	}
	for(int i = 1; i <= left; i++)
	{
		for(int i = 500; i >= 1; i--)
		{
			a[i] *= 2;
		}
		for(int i = 500; i >= 1; i--)
		{
			a[i - 1] += a[i] / 10;
			a[i] = a[i] % 10;
		}
	}
	a[500]--;
	cout << ceil(p * log10(2)) << endl;
	for(int i = 1; i <= 500; i++)
	{
		cout << a[i];
		if(i % 50 == 0) cout << endl;
	}
	return 0;
}
