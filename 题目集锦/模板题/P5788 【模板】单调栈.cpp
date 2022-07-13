#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
stack <int> s;
int a[Max];
int n, top = 0;
vector <int> ans;

int main()
{
	cin >> n;
	s.push(-1);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		{
			s.pop();
		}
		if(s.empty())
		{
			ans.push_back(0);
		}
		else ans.push_back(s.top());
		s.push(i);
 	}

	for(int i = ans.size() - 1; i >= 0; i--)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}

/*
5
3 4 2 7 5
*/