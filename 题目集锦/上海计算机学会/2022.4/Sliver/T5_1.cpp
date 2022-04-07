#include <iostream>
#include <stack>
using namespace std;

stack<char> a;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int cnt = 0, res = 0;
    while(cnt <= len - 1)
    {
        if(s[cnt] == '(' || s[cnt] == '[')
        {
            a.push(s[cnt]);
        }
        if(a.empty() && (s[cnt] == ')' || s[cnt] == ']')) res++;
        if((s[cnt] == ')' || s[cnt] == ']') && !a.empty())
        {
            if(s[cnt] == ')' && a.top() == '(') a.pop();
            else if(s[cnt] == ')' && a.top() != '(') res++;
            if(s[cnt] == ']' && a.top() == '[') a.pop();
            else if(s[cnt] == ']' && a.top() != '[') res++;
        }
        cnt++;
    }
    cout << a.size() + res << endl;
    return 0;
}