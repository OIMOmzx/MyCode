#include <iostream>
using namespace std;

char op;
int n, m, p, q;
bool a[10010][10010];
int num[10010];

int main()
{
    cin >> n >> m;
    while(m--)
    {
        cin >> op;
        if(op == '+')
        {
            cin >> p >> q;
            a[p][q] = 1;
            a[q][p] = 1;
        }
        else if(op == '-')
        {
            cin >> p >> q;
            a[p][q] = 0;
            a[q][p] = 0;
        }
        else if(op == '!')
        {
            cin >> p;
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[p][i] == 1) num[i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}