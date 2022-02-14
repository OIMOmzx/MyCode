#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> a;
string s;
int num1, num2;

int main()
{
    getline(cin, s);
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ') continue;
        if(s[i] >= '0' && s[i] <= '9')
        {
            a.push(s[i] - '0');
        }
        if(s[i] == '+')
        {
            if(a.empty()) break;
            num1 = a.top();
            a.pop();
            if(a.empty()) break;
            num2 = a.top();
            a.pop();
            a.push(num2 + num1);
            a.top() %= 10;
        }
        if(s[i] == '-')
        {
            if(a.empty()) break;
            num1 = a.top();
            a.pop();
            if(a.empty()) break;
            num2 = a.top();
            a.pop();
            a.push(num2 - num1);
            a.top() %= 10;
        }
        if(s[i] == '*')
        {
            if(a.empty()) break;
            num1 = a.top();
            a.pop();
            if(a.empty()) break;
            num2 = a.top();
            a.pop();
            num1 %= 10, num2 %= 10;
            a.push(num2 * num1);
            a.top() %= 10;
        }
    }
    if(a.top() < 0) cout << 10 - abs(a.top()) << endl;
    else cout << a.top() % 10 << endl;
    return 0;
}