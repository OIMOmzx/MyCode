#include <iostream>
using namespace std;

long long jc(int n, int m)
{
    if(m == 0) return 1;
    if(m == 1) return n;
    return jc(n, m - 1) * n;
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    long long sum = 0;
    //cout << jc(26, 5) << endl;
    for(int i = 0; i < len; i++)
    {
        sum += ((s[i] - 'a') * jc(26, len - 1 - i));
    }
    cout << sum + jc(26,(len - 1));
    return 0;
}
