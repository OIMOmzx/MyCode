#include <iostream>
using namespace std;

const int Max = 10000010;
int q[Max], a[Max];
int n, t, head = 1, tail = 0;

int main()
{
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		while(head <= tail && a[q[tail]] >= a[i]) tail--;
		q[++tail] = i;
		while(q[head] <= i - t) head++;
		if(i >= t)
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
		while(q[head] <= i - t) head++;
		if(i >= t)
		{
			cout << a[q[head]] << " ";
		}
	}
	return 0;
}