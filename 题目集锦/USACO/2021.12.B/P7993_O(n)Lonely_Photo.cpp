#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const long long Max = 10000010;
long long a[Max], n, ans, res = 1;
char s[Max];

int main()
{
	cin >> n;
    cin >> (s + 1);
	a[res]++;
	for (long long i = 2; i <= n; i++)
    {
		if (s[i] == s[i - 1]) 
        {
			a[res]++;
		}
		else a[++res]++;
	}
	for (long long i = 1; i < res; i++)
    {
		if (a[i] == 1) 
        {
            ans += a[i - 1] * a[i + 1] + a[i + 1] - 1;
        }
		else 
        {
            ans += a[i] + a[i + 1] - 2;
        }
	}
	cout << ans << endl;
    return 0;
}