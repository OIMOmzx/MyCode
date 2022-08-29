#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Max = 1000010;
struct node
{
	int a, b;
}t[Max];

int m[Max], s[Max], ans[Max];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i].a);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i].b);
	}
	for(int i = 1; i <= n; i++)
	{
		m[i] = min(t[i].a, t[i].b);
		s[i] = i;
	}
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(m[i] > m[j])
			{
				swap(m[i], m[j]);
				swap(s[i], s[j]);	
			}
		}
	}
	int k = 0, p = n + 1;
	for(int i = 1; i <= n; i++)
	{
		if(m[i] == t[s[i]].a)
		{
			k++;
			ans[k] = s[i];
		}
		else
		{
			p--;
			ans[p] = s[i];
		}
	}
	k = 0, p = 0;
	for(int i = 1; i <= n; i++)
	{
		k += t[ans[i]].a;
		p = max(k, p);
		p += t[ans[i]].b;
	}
	cout << p << endl;
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}
