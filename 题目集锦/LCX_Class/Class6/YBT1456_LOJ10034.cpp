#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#define Max 1000010
using namespace std;

map<string, bool> a;
int t;
string s;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s[0] == 'a') 
        {
            getline(cin, s);
            a[s] = 1;
        }
        else
        {
            getline(cin, s);
            if(a[s]) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}