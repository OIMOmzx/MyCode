#include <iostream>
using namespace std;

int y;

int main()
{
    cin >> y;
    if(y % 4 == 0 && y % 100 != 0) cout << "Leap year" << endl;
    else if(y % 400 == 0) cout << "Leap year" << endl;
    else cout << "Common year" << endl;
    return 0;
}