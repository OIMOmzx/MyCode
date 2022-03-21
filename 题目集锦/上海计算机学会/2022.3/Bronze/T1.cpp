#include <iostream>
using namespace std;

long long n;

int main()
{
    cin >> n;
    if(n > 0) cout << "Positive" << endl;
    if(n == 0) cout << "Zero" << endl;
    if(n < 0) cout << "Negative" << endl;
    return 0;
}