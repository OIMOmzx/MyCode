/*
    author : mezt.
    write in : home, Windows11
    time : 2021.10.16
    using : Visual Studio Code
*/
#include <bits/stdc++.h>
using namespace std;
void before(string middle, string after)
{
    if(middle.size() > 0)
    {
        char ch = after[after.size() - 1];
        cout << ch;
        int res = middle.find(ch);
        before(middle.substr(0, res), after.substr(0, res));
        before(middle.substr(res + 1), after.substr(res, middle.size() - res - 1));
    }
}
int main()
{
    string middle, after;
    cin >> middle >> after;
    before(middle, after);
    cout << endl;
    return 0;
}