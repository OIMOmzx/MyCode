#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 5000010;
bool is[Max];
int prime[Max], n[Max], cnt = 1, t, x;
int sum = -0x3f3f3f3f;

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
	memset(is, 1, sizeof(is));
	is[0] = 0, is[1] = 0;
	t = read();
    for(int i = 1; i <= t; i++)
    {
        cin >> n[i];
        sum = max(sum, n[i]);
    }
	for(int i = 2; i <= sum * 2; i++)
	{
		if(is[i])
		{
			prime[cnt] = i, cnt++;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= sum; j++)
		{
			is[prime[j] * i] = 0;
			if(i % prime[j] == 0) break;
		}
	}
    for(int i = 1; i <= t; i++)
    {
        if(n[i] == 1) cout << "1" << endl;
        for(int j = 1; j <= cnt; j++)
        {
            if(prime[j] <= n[i] && prime[j + 1] > n[i])
            {
                cout << prime[j] << endl;
            }
        }
    }
	return 0;
}