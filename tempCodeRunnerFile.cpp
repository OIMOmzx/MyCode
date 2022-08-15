#include <iostream>
using namespace std;

int main()
{
    char n[] = "一啊女方且染发啊的法";
    char a = '三', d = '一';
    char *p = &n[0];
    while(p != &d)
    {
        p++;
    }
    cout << *p;
    return 0;
}