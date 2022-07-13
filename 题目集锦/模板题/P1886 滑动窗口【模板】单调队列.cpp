#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int q[Max], head = 1, tail = 0;
int a[Max];
int n, k;

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		while(head <= tail && a[q[tail]] >= a[i]) tail--;
		q[++tail] = i;
		while(q[head] <= i - k) head++;
		if(i >= k)
		{
			cout << a[q[head]] << " ";
		}
	}
	cout << endl;
    
	head = 1, tail = 0;
	for(int i = 1; i <= n; i++)
	{
		while(head <= tail && a[q[tail]] <= a[i]) tail--;
		q[++tail] = i;
		while(q[head] <= i - k) head++;
		if(i >= k)
		{
			cout << a[q[head]] << " ";
		}
	}
	return 0;
}