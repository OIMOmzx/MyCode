#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

const long long Max = 2200010;
const long long mod =  2181271;
long long hashh[Max];

struct node
{
	int ne, val;
}t[Max];

bool check(int res, int cnt)
{
	for(int i = hashh[cnt]; i; i = t[i].ne)
	{
		if(res == t[i].val)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	hashh[1] = t[1].val = 1;
	long long tmp1 = 1;
	for(long long i = 1; i <= 2e6; i++)
	{
		tmp1 = ((long long)a * tmp1 + (tmp1 % b)) % c;
		long long tmp2 = tmp1 % mod;
		if(check(tmp1, tmp2))
		{
			printf("%lld\n", i);
			return 0;
		}
		t[i + 1].val = tmp1;
		t[i + 1].ne = hashh[tmp2];
		hashh[tmp2] = i + 1;
	}
	printf("-1\n");
	return 0;
}