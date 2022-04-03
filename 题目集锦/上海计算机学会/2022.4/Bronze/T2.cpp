#include <iostream>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= 2 * n + 1; i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1; j <= 2 * m + 1; j++)
            {
                if(j % 2 == 1) cout << "+";
                else cout << "-";
            }
        }
        if(i % 2 == 0)
        {
            for(int j = 1; j <= 2 * m + 1; j++)
            {
                if(j % 2 == 1) cout << "|";
                else cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}