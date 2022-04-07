#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<char> a;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    //cout << s[0] << endl;
    int cnt = 0, res = 0;
    while(cnt <= len - 1)
    {
        if(s[cnt] == '(' || s[cnt] == '[')
        {
            a.push(s[cnt]);
        }
        //if(a.empty() && (s[cnt] == ')' || s[cnt] == ']')) res++;
        if((s[cnt] == ')' || s[cnt] == ']') && !a.empty())
        {
            if(s[cnt] == ')' && a.top() == '(') a.push(s[cnt]);
            if(s[cnt] == ']' && a.top() == '[') a.push(s[cnt]);
        }
        cnt++;
    }
    vector<char> tmp;
    tmp.push_back('k');
    while(!a.empty())
    {
        tmp.push_back(a.top());
        a.pop();
    }
    for(int i = tmp.size(); i >= 2; i--)
    {
        if(tmp[i] == ')' || tmp[i] == ']') break;
        else if(tmp[i - 1] != ')' && tmp[i] == '(') res++;
        else if(tmp[i - 1] != ']' && tmp[i] == '[') res++;
    }
    cout << len - (tmp.size() - 1) +  res << endl;
    return 0;
}