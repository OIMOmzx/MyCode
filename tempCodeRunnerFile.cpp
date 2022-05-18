#include <iostream>
#include <cstring>
#define Max 1000010
using namespace std;

unsigned long long num;
char a[Max];

unsigned long long jc(int n, int times)
{
    if(times == 0) return 1;
    if(times == 1) return n;
    return n * jc(n, times - 1);
}

int main()
{
    cin >> (a + 1);
    int len = strlen(a + 1);
    for(int i = 1; i <= len; i++)
    {
        num += (a[i] - '0') * jc(10, len - i);
    }
    cout << num << endl;
    return 0;
}