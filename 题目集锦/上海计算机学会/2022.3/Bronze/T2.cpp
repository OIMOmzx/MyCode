#include <iostream>
using namespace std;

long long n;

int main()
{
    cin >> n;
    for(int i = 0; i <= n - 1; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for(int j = 1; j <= (n - i) * 2 - 1; j++)
        {
            cout << "*";
        }
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        for(int j = 1; j <= (n - i) * 2 -1; j++)
        {
            cout << "*";
        }
        for(int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}