#include <iostream>
using namespace std;

const int Max = 1000010;
int n, ne[Max], j = 0;
char s[Max];

int main()
{
    cin >> n;
    cin >> (s + 1);
    for(int i = 2; i <= n; i++)
    {
        while(j && s[i] != s[j + 1]) j = ne[j];
        if(s[i] == s[j + 1]) j++;
        ne[i] = j;
    }
    cout << n - ne[n];
    return 0;
}