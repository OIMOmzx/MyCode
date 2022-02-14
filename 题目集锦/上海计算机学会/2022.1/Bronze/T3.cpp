#include <iostream>
#include <cstring>
using namespace std;

const int Max = 4000010;
char a[Max];
char s[Max];
int top = 0;

bool empty()
{
	if(top == 0) return 1;
	return 0;
}

void push(char n)
{
	s[++top] = n;
}

int query()
{
	if(empty()) return -1;
	return s[top];
}

void pop()
{
	s[top] = 0;
	top--;
}

int main()
{
    cin >> (a + 1);
    for(int i = 1; i <= strlen(a + 1); i++)
    {
        if(a[i] == '[' || a[i] == '(' || a[i] == '{')
        {
            push(a[i]);
            //cout << s.top() << endl;
        }
        else
        {
            if(query() == '[' && a[i] == ']')
            {
                //cout << s.top() << endl;
                if(!empty()) pop();
                continue;
            }
            if(query() == '(' && a[i] == ')')
            {
                //cout << s.top() << endl;
                if(!empty()) pop();
                continue;
            }
            if(query() == '{' && a[i] == '}')
            {
                //cout << s.top() << endl;
                if(!empty()) pop();
                continue;
            }
            else continue;
        }
    }

    if(empty()) cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl;
    return 0;
}