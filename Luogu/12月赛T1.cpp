#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const unsigned long long Max = 10000010;
unsigned long long n, tar, a[Max];
unsigned long long sum = 0;
long double aver, fan;
long double res = 0x3f3f3f3f3f3f3f;
bool flag = 0;
unsigned long long ans;
long double cnt;

inline unsigned long long read()
{
	unsigned long long now = 0, nev = 1; 
    char c = getchar();
	while(c < '0' || c > '9') 
    { 
        if(c == '-') nev = -1; 
        c = getchar();
    }
	while(c >= '0' && c <= '9') 
    { 
        now = (now << 1) + (now << 3) + (c & 15); 
        c = getchar(); 
    }
	return now * nev;
}


int main()
{
    n = read(), tar = read();
    for(unsigned long long i = 1; i <= n; i++)
    {
        a[i] = read();
        sum += a[i];
    }
    aver = sum * 1.0 / n;
    for(unsigned long long i = 1; i <= n; i++)
    {
        fan += (a[i] - aver) * (a[i] - aver);
    }
    fan = fan / n;
    if(fan == 0) cout << "No answer!" << endl;
    else
    {
        for(unsigned long long i = 1; i <= Max; i++)
        {
            cnt = fan * i * i;
            if(abs(cnt - tar) < res)
            {
                res = abs(cnt - tar);
            }
            else if(abs(cnt - tar) >= res)
            {
                ans = i - 1;
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout << ans << endl;
    }
    return 0;
}