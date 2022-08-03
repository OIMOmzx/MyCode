#include <iostream>
#include <algorithm>
#include <unistd.h>
using namespace std;
int prime[1000010], k, n, cnt;
bool vis[1000010];

long long quickpow(long long res, long long time, long long mod)
{
	long long sum = 1;
	while(time)
	{
		if(time % 2 == 1)
		{
			sum = sum * res % mod;
		}
		time /= 2;
		res = res * res % mod;
	}
	return sum % mod;
}

int main()
{
    k = 1000;
    //cout << quickpow(3, 2019, 10) << endl;
    vis[1] = 1;
    for(int i = 2; i <= k; i++)
    {
        if(vis[i] == 0) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= k; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    
    for(int i = 2; i <= cnt; i++)
    {
        
        for(int j = i + 1; j <= cnt; j++)
        {
            for(int k = 1; k <= 10000; k++)
            {
                int p = prime[i], q = prime[j];
                cout << p << ", " << q <<  endl;
                if((quickpow(k, q - 1, p) + q) % p == 0 && (quickpow(k, p - 1, q) + p) % q == 0)
                {
                    cout << "3ejwiucndniuenwrufoy8qc3w" << endl;
                    cout << p << "," << q << "," << k;
                    sleep(10);
                }
            }
        }
    }
    
    return 0;
}
