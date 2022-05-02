#include <iostream>
using namespace std;

void print1()
{
    cout << "/\\  ";
}

void print2()
{
    cout << "/__\\";
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i++)
    {
        for(int j = 1; j <= 2 * n - i; j++)
        {
            cout << " ";
        }
        if(i % 2 == 1)
        {
            for(int j = 1; j <= (i + 1) / 2; j++)
            {
                print1();
            }
        }
        else if(i % 2 == 0)
        {
            for(int j = 1; j <= (i / 2); j++)
            {
                print2();
            }
        }
        for(int j = 1; j <= 2 * n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}