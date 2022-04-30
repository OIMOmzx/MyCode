#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> Q;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        Q.push(k);
        q.push(k); 
    }
    int a = 0, b = 0;
    for(int i = 1; i < n; i++)
    {
        a = Q.top();
        Q.pop();
        b = Q.top();
        Q.pop();
        b = a * b + 1;
        Q.push(b);
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        b = a * b + 1;
        q.push(b);
    }
    cout << q.top() - Q.top() << endl;
    return 0;
}