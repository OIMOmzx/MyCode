#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int cnt = 10;
int n = 81;
vector<int> a;
vector<int> b;
int suma, sumb, ka, kb;
double sum1, sum2;

int main()
{
    srand(time(0));
    for(int i = 1; i <= cnt; i++)
    {
        suma = 0, sumb = 0, ka = 0, kb = 0;
        for(int j = 1; j <= n; j++)
        {
            int num = rand() % 3;
            int now = rand() % 1000 + 1;
            if(num == 0)
            {
                suma += now;
                ka++;
            }
            else
            {
                sumb += now;
                kb++;
            }
        } 
        cout << suma * 1.0 / ka << ", " << sumb * 1.0 / kb << endl;

        sum1 += suma * 1.0 / ka;
        sum2 += sumb * 1.0 / kb;
    }
    cout << sum1 * 1.0 / cnt << ", " << sum2 * 1.0 / cnt;
    return 0;
}