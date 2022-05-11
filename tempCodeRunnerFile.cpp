#include <iostream>
using namespace std;

int main() 
{
for(int i = 1; i <= 1000000; i++)
{
if(i * i % 2017 == 105) 
{
    cout << i << endl;
    
    }
}
 return 0;
}