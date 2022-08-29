#include<bits/stdc++.h>            
using namespace std;
int main()
{
	int a,b,d=0;
	cin>>a>>b;
	for (int c=1;c<=a;c++)
	{
		if (pow(c,b)<=a) d++;
		else break;
	}
	cout<<d;
 } 