#include <cstdio>
#include <iostream>
using namespace std;

int a, n, i, j;
 
int main()
{
    cin >> n;
    while(n--)
    {
        i = 0, j = 0, a = 0;
        cin >> a;
        if (a <= 1)
        {
            printf("%d", 1);
        }
        else
        {
            for (j = a; j > 1; j--)
            {
                for (i = 2; i < j; i++)
                {
                    if (0 == j % i)
                    {
                        break;
                    }
                }
                if (i == j)
                {
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
    return 0;
}