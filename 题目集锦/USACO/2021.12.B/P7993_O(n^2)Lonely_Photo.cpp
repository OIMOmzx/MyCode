/*
ID: handsomemzx
TASK: Lonely Photo 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 5010;
long long n;
long long a[Max][Max];
char s[1000010];

int main()
{
    //ofstream fout("Lonely Photo.out");
    //ifstream fin("Lonely Photo.in");
    cin >> n;
    cin >> (s + 1);
    int len = strlen(s + 1);
    for(int i = 1; i <= len; i++)
    {
        for(int j = i; j <= len; j++)
        {
            if(s[j] == 'G') a[i][j] = a[i][j - 1] + 1;
            else a[i][j] = a[i][j - 1];
        }
    }
    long long ans = 0;
    for(int i = 1; i <= len; i++)
    {
        for(int j = i + 2; j <= len; j++)
        {
            //cout << i << " " << j << ':' << a[i][j] << "   ;";
            if(a[i][j] == 1 || abs(i - j) == a[i][j]) ans++;
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
/*
5
GHGHG

*/