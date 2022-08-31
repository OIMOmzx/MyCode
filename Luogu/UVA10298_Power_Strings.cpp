#include <iostream>
#include <cstring>
using namespace std;

const int Max = 1000010;
int n, ne[Max], j = 0;
char s[Max];

int main()
{
    while(1)
    {
        cin >> (s + 1);
        n = strlen(s + 1);
        if(s[1] == '.' && n == 1) break;
        j = 0;
        for(int i = 2; i <= n; i++)
        {
            while(j && s[i] != s[j + 1]) j = ne[j];
            if(s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        cout << n / (n - ne[n]) << endl;
    }
    return 0;
}

/*
abcd
aaaa
ababab
.
*/