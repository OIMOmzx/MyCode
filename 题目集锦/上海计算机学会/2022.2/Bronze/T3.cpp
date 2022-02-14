#include <iostream>
#include <cstring>
using namespace std;

const int Max = 1000010;
char s[Max];
int len, op = 1;
int r = 0, c = 0;

int main()
{
    cin >> (s + 1);
    int len = strlen(s + 1);
    for(int i = 1; i <= len; i++)
    {
        if(s[i] == 'R')
        {
            op = (op + 1) % 4;
        }
        if(s[i] == 'L')
        {
            op = (op + 3) % 4;
        }
        if(s[i] == 'F')
        {
            if(op == 1) r++;
            if(op == 2) c--;
            if(op == 3) r--;
            if(op == 0) c++;
        }
        if(s[i] == 'B')
        {
            if(op == 1) r--;
            if(op == 2) c++;
            if(op == 3) r++;
            if(op == 0) c--;
        }
    }
    cout << r << " " << c;
    return 0;
}