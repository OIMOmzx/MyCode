#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n;
string a[210];
int now_line, now_pos;
int next_line, next_pos;
bool option = 0;

int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        getline(cin, (a[i]));
    }
    /*
    for(int i = 2; i <= n + 1; i++)
    {
        for(int j = 0; j <= a[i].length(); j++)
        {
            a[i - 1][j] = a[i][j];
        }
    }
    */
    //cout << endl;
    /*
    for(int i = 1; i <= n; i++)
    {
        int len = .length()(a[i]);
        for(int j = len; j >= 0; j--)
        {
            a[i][j] = a[i][j + 1];
        }
    }
    */
   
   //cout << endl;
   /*
   for(int i = 1; i <= n; i++)
   {
    for(int j = 0; j <= a[i].length(); j++)
    {
        cout << a[i][j];
    }
    cout << endl;
   }
   */
   
    //cout << endl;
    int cnt = 0;
    for(int i = 0; i <= a[n].length(); i++)
    {
        //cout << a[n][i];
        if(a[n][i] == a[n][i + 1] && a[n][i] == '/') cnt++;
        //cout << cnt << endl;
        if(cnt == 3) 
        {
            now_line = n;
            next_line = n;
            now_pos = i;
            next_pos = i + 1;
            break;
        }
    }
    //cout << now_line << ", " << next_line << ", " << now_pos << ", " << next_pos << endl;
    
    while(1)
    {
        option = !option;
        if(option == 1)//up
        {
            //cout << a[now_line - 1].length() << endl;
            if(now_pos >= a[now_line - 1].length())
            {
                now_pos = a[now_line - 1].length() - 1;
                now_line -= 1;
                next_pos = 0;
            }
            else
            {
                //cout << "OOKKK" << endl;
                now_line -= 1;
                next_line -= 1;
            }
        }
        else if(option == 0)//right
        {
            now_pos += 1;
            next_pos += 1;
            //cout << now_line << "line" << ", " << "length" << a[now_line].length() << endl;
            if(next_pos >= a[now_line].length())//change to a new line
            {
                next_pos = 0;
                next_line = now_line + 1;
            }
            if(now_pos >= a[now_line].length())//change to a new line
            {
                now_pos = 0;
                now_line = now_line + 1;
            }
        }
        
        //cout << "now: " << now_line << ", " << now_pos << " " << endl;
        //cout << "next:" << next_line << ", " << next_pos << endl;
        
        if(now_line == 1)//come to an end
        {
            //cout << "fr" << endl;
            //cout << a[now_line].length() << endl;
            if(now_pos < a[now_line].length() - 1) cout << a[now_line][now_pos + 1] << endl;
            else cout << a[2][0] << endl;
            break;
        } 
    }
    
    return 0;
}