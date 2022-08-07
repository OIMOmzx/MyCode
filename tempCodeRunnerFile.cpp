#include <iostream>
using namespace std;

int main()
{
    cout << (0 ^ 61 ^ 0 ^ 62) << endl;
    /*
    for(int i = 1; i <= 10; i++)
    {
        bool flag = 0;
        int k = i * 10 + 1;
        for(int j1 = 0; j1 <= k; j1++)
        {
            for(int j2 = 0; j2 <= k; j2++)
            {
                for(int j3 = 0; j3 <= k; j3++)
                {
                   if((j1 ^ j2 ^ j3) == 0 && j1 + j2 + j3 == k)
                   {
                        cout << j1 << " " << j2 << " " << j3 << endl;
                        flag = 1;
                        break;
                   }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout << "3jnfqjd" << endl;
    }
    */
    return 0;
}