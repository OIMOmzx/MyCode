#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int Max = 1000010;
const int b = 131;
char s[Max];
int a[Max], poww[Max];
vector<int> ans;

int main()
{
    while(cin >> (s + 1))
    {
        int len = strlen(s + 1);
        poww[0] = 1;
        for(int i = 1; i <= len; i++)
        {
            poww[i] = poww[i - 1] * b;
        }
        for(int i = 1; i <= len; i++)
        {
            a[i] = a[i - 1] * b + s[i];
        }
        for(int i = 1; i <= len; i++)
        {
            if(a[i] == a[len] - a[len - i] * poww[i])
            {
                ans.push_back(i);
            }
        }
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        ans.clear();
        cout << endl;
    }
    return 0;
}