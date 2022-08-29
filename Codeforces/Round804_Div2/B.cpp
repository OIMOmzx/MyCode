#include <iostream>
using namespace std;

int t, x, y;
 
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(x == 2)
        {
            string s1 = "", s2 = "";
            for(int i = 1; i <= y / 2; i++)
            {
                if(i % 2 == 0)
                {
                    s1 += "0 1 ";
                    s2 += "1 0 ";
                }
                if(i % 2 == 1)
                {
                    s1 += "1 0 ";
                    s2 += "0 1 ";
                }
            }
            cout << s1 << endl << s2 << endl;
        }
        else if(y == 2)
        {
            for(int i = 1; i <= x / 2; i++)
            {
                if(i % 2 == 0)
                {
                    cout << "0 1" << endl << "1 0" << endl;
                }
                if(i % 2 == 1)
                {
                     cout << "1 0" << endl << "0 1" << endl;
                }
            }
        }
    }
    return 0;
}