#include <iostream>
#include <iomanip>
using namespace std;

int n;
double a, b, c, maxn, minn;
double suma, sumb, sumc;

int main()
{
    cin >> n;
    cin >> a >> b >> c;
    suma = a * (n - 1), sumb = b * n, sumc = c * (n - 1);
    maxn = sumb - suma, minn = sumb - sumc;
    cout << fixed << setprecision(2) << (sumb - maxn - minn) * 1.0 / (n - 2);
    return 0;
}