#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Max = 10000010;
long long a[Max], n, tar;
bool flag = 0;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> tar;
    int st = 1, ed = n;
    while(st <= ed)
    {
        if(a[st] + a[ed] == tar && st != ed) 
        {
            cout << "Yes" << endl;
            flag = 1;
            break;
        }
        if(a[st] + a[ed] > tar) st++;
        else ed--;
    }
    if(flag == 0) cout << "No" << endl;
    return 0;
}