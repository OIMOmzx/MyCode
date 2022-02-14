#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int Max = 10000010;
multiset<long long> s;
long long a[Max], n, tar;
bool flag = 0;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    cin >> tar;
    for(int i = 1; i <= n; i++)
    {
        if(tar - a[i] == a[i] && s.count(a[i]) == 1) 
        {
            break;
        }
        else 
        {
            if(s.count(tar - a[i]) > 0)
            {
                cout << "Yes" << endl;
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0) cout << "No" << endl;
}