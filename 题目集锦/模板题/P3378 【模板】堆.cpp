#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int heap[Max];
int n, type, p, maxn;

void add(int x)
{
	int lc, fa;
	maxn++;
	heap[maxn] = x;
	lc = maxn;
	while(lc > 1)
	{
		fa = lc / 2;
		if(heap[lc] >= heap[fa]) return;
		swap(heap[lc], heap[fa]);
		lc = fa;
	}
	return;
}

void del()
{
	int lc = 1, rc = 2, fa = 1;
	heap[1] = heap[maxn];
	maxn--;
	while(fa * 2 <= maxn)
	{
		lc = fa * 2;
		rc = fa * 2 + 1;
		if(rc <= maxn && heap[lc] > heap[rc]) lc = rc;
		if(heap[lc] >= heap[fa]) return;
		swap(heap[lc], heap[fa]);
		fa = lc;
	}
}

int main()
{
	cin >> n;
	while(n--)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> p;
			add(p);
		}
		if(type == 2)
		{
			cout << heap[1] << endl;
		}
		if(type == 3)
		{
			del();
		}
	}
	return 0;
}