#include <iostream>
#include <cstring>
using namespace std;

const int Max = 10000010;
bool flag = 1;
char s[Max];

void ish(char s[])
{
    int len = strlen(s + 1);
    for(int i = 1; i <= len / 2; i++)
    {
        if(s[i] != s[len - i + 1])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 0) cout << "Non-Palindromic Number" << endl;
    else cout << "Palindromic Number" << endl;
}

int main()
{
    cin >> (s + 1);
    ish(s);
    return 0;
}