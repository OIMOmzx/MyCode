#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int a=1,b=0,c=0;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='A')
		{
			swap(a,b);
		}
		else if(str[i]=='B')
		{
			swap(b,c);
		}
		else if(str[i]=='C')
		{
			swap(a,c);
		}
	}
	if(a==1)
	{
		cout<<1;
	}
	else if(b==1)
	{
		cout<<2;
	}
	else
	{
		cout<<3;
	}
   	return 0;
}