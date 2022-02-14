#include <iostream>
using namespace std;
int father[10000010];
void init(int n)
{
    for(int i = 1; i <= n; i++) father[i] = i;
}
int find(int x)
{
    if(x != father[x]) father[x] = find(father[x]);
    return father[x];
}
int merge(int a, int b)
{
    int p = find(a);
    int q = find(b);
    if(p == q) return 0;
    else if(p > q) father[p] = q;
    else father[q] = p;
    return 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    int a, b, c;
    while(m--)
    {
        cin >> c >> a >> b;
        if(c == 1) merge(a, b);
        if(c == 2)
        {
            if(find(father[a]) == find(father[b])) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}