#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int Max = 10000010;
const int P = 37;
char s[Max];
int n, t, l1, l2, r1, r2;
ull h[Max], res[Max];

int main()
{
	cin >> n; 
    for(int i = 1; i <= n; i++)
    {
        cin >> (s + 1);
        ull ans = 0;
        int len = strlen(s + 1);
	    for(int j = 1; j <= len; j++)
	    {
            //cout << s[j] << endl;
		    ans = P * ans + (ull)s[j];
	    }
        res[i] = ans;
    }
    sort(res + 1, res + n + 1);
    long long ans = 1;
    for(long long i = 1; i < n; i++)
    {
        if(res[i] != res[i + 1]) ans++;
    }
    cout << ans << endl;
	return 0;
} 