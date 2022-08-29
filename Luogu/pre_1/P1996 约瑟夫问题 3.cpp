#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    queue<int> a;
	int n, m, d, res = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) a.push(i);
	while(!a.empty())
	{
		if(res == m)
		{
			cout << a.front() << " ";
			a.pop(), res = 1;
		}
		else if(res != m)
		{
			res++;
			a.push(a.front());
			a.pop();
		}
	}
	return 0;
}
