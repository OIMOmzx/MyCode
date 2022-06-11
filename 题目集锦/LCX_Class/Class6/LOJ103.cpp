#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define bkkk 131
#define Max 1000010
using namespace std;

const int mod = 1e9 + 7;

string a, b;
long long sum1[Max], sum, ans, poww[Max];

int getnum(char x)
{
    if (x < 'a') return x - 'A' + 1;
    else return x - 'a' + 27;
}

int main()
{
    cin >> a >> b;
    long long len1 = a.length(), len2 = b.length();
    poww[0] = 1;
    for(int i = 1; i <= len1; i++)
    {
        poww[i] = poww[i - 1] * bkkk % mod;
        sum1[i] = sum1[i - 1] * bkkk % mod + getnum(a[i - 1]) % mod;
        sum1[i] %= mod;
    }
    for(int i = 0; i < len2; i++)
    {
        sum = sum * bkkk % mod + getnum(b[i]);
        sum %= mod;
    }
    for(int i = 0; i <= len1 - len2; i++)
    {
        if(sum == (mod + sum1[i + len2] - (sum1[i] * poww[len2]) % mod) % mod)
        {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}