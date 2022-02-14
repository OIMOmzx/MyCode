/*
ID: handsomemzx
TASK: Air Cownditioning
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 100010;
int n;
int p[Max], t[Max];
int diff1[Max], diff2[Max];
int sum1, sum2;

int main()
{
    ofstream fout("Air Cownditioning.out");
    ifstream fin("Air Cownditioning.in");
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        diff1[i] = p[i] - p[i - 1];
        //cout << diff1[i] << ' ';
    }
    //cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
        diff2[i] = t[i] - t[i - 1];
        //cout << diff2[i] << ' ';
    }
    //cout << endl;
    for(int i = 1; i <= n; i++)
    {
        diff1[i] = diff1[i] - diff2[i];
    }
    for(int i = 1; i <= n; i++)
    {
        sum1 += diff1[i];
        sum2 += abs(diff1[i]);
    }
    cout << sum1 + (sum2 - sum1) / 2 << endl;
    return 0;
}

/*
5
1 5 3 3 4
1 2 2 2 1
*/