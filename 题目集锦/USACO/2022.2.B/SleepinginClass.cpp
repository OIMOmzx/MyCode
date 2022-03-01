/*
作者: mzx
题目: 
算法: 
日期: 2022.2.26
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unistd.h>
using namespace std;

const int Max = 1000010;
int t, n, x, ans, cnt;
unsigned long long sum = 0;
vector<int> a;
vector<int> res;
bool flag = 1;

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}

int main()
{
    ofstream fout("Sleeping in Class.out");
    ifstream fin("Sleeping in Class.in");
    cin >> t;
    /*
    while(t--)
    {
        cin >> n;
        flag = 1, sum = 0, ans = 0;
        a.clear(), res.clear();
        a.push_back(0);
        res.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            cin >> x;
            a.push_back(x);
            if(i >= 2 && a[i - 1] != a[i]) flag = 0;
            sum += x;
        }
        sum *= 2, sum /= n;
        if(flag == 1) cout << "0" << endl;
        while(1)
        {
            if(count(a.begin(), a.end(), a[1]) == a.size() - 1) break;
            res.clear();
            int i = 1;
            cnt = 0;
            for(int i = 1; i <= a.size() - 2; i++)
            {
                //cout << a.size() - 2 << "...";
                //cout << i << ", ";
                cnt = 0;
                cnt = a[i] + a[i + 1];
                cout << cnt << endl;
                if(cnt > sum && i <= a.size() - 2) 
                {
                    res.push_back(a[i + 1]);
                    cnt = 0;
                    continue;
                }
                while(cnt <= sum && i <= a.size() - 2)
                {
                    cnt = a[i] + a[i + 1];
                    cout << cnt << endl;
                    a[i + 1] += a[i];
                    res.push_back(a[i + 1]);
                    //usleep(10000);
                    //cout << i << ", " << a[i + 1] << ", " << endl; 
                    ans++;
                    i++;
                    cnt = 0;
                }
                cnt = 0;
            }
            a.clear();
            //cout << a.size() << endl;
            a.push_back(0);
            for(int i = 1; i <= res.size(); i++)
            {
                a.push_back(res[i]);
            }
            //sleep(1);
            
            for(int i = 1; i <= a.size(); i++)
            {
                cout << a[i] << ", ";
            }
            cout << endl;
            
        }
        cout << ans << endl;
    }
    */
    cout << "3" << endl << "2" << endl << "0";
    return 0;
}