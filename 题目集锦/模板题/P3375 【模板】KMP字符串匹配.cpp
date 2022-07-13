#include <bits/stdc++.h>
using namespace std;

const int Max = 1000010;
char s1[Max], s2[Max];
int j = 0, ne[Max];

int main()
{
	cin >> s1 + 1 >> s2 + 1;
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	for(int i = 2; i <= len2; i++)
	{
		while(j && s2[i] != s2[j + 1]) j = ne[j];
		if(s2[i] == s2[j + 1])
		{
			j++;
		}
		ne[i] = j;
	}
	j = 0;
	for(int i = 1; i <= len1; i++)
	{
		while(j && s1[i] != s2[j + 1]) j = ne[j];
		if(s1[i] == s2[j + 1])
		{
			j++;
		}
		if(len2 == j)
		{
			cout << i - len2 + 1 << endl;
			j = ne[j];
		}
	}
	for(int i = 1; i <= len2; i++)
	{
		cout << ne[i] << " ";
	}
	return 0;
}