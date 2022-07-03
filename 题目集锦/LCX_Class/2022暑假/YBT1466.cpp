#include <iostream>
#include <cstring>
using namespace std;

string s;
int ne[1000010];

void kmp(int n)
{
    int i = 1, j = 0;
    ne[0] = 0;
    while (i < n) 
    {
        if (s[i] == s[j]) ne[i] = j + 1, i++, j++;
        else if (!j) i++;
        else j = ne[j - 1];
    }
}

int main()
{
    while(cin >> s)
    {
        if(s == ".") break;
        memset(ne, 0, sizeof(ne));
        int n = s.length();

        kmp(n);

        int tmp = n - ne[n - 1];
        if(n % tmp == 0) cout << n / tmp << endl;
        else cout << "1" << endl;
    }
    return 0;
}