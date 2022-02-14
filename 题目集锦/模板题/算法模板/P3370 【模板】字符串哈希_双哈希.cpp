#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int Max = 10000010;
const int P = 37;
const ull mod1 = 19260817, mod2 = 19660813;
char s[Max];
int n;
ull res1[Max], res2[Max];

struct node
{
    int val1, val2;
}h[Max];

ull hash1(char s[])
{
	ull ans = 0, len = strlen(s + 1);
	for(ull i = 1; i <= len; i++)
    {
		ans = (P * ans + (ull)s[i]) % mod1;
	}
	return ans;
}

ull hash2(char s[])
{
	ull ans = 0, len = strlen(s + 1);
	for(ull i = 1; i <= len; i++)
    {
		ans = (P * ans + (ull)s[i]) % mod2;
	}
	return ans;
}

bool cmp1(node a, node b)
{
    return a.val1 < b.val1;
}
bool cmp2(node a, node b)
{
    return a.val2 < b.val2;
}

int main()
{
	cin >> n; 
    for(int i = 1; i <= n; i++)
    {
        cin >> (s + 1);
        h[i].val1 = hash1(s);
        h[i].val2 = hash2(s);
    }
    sort(h + 1, h + n + 1, cmp1);
    sort(h + 1, h + n + 1, cmp2);
    ull ans = 1;
    for(int i = 1; i < n; i++)
    {
        if(h[i].val1 != h[i + 1].val1 || h[i].val2 != h[i + 1].val2)
        {
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
} 

