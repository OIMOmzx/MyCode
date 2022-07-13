/*
    author : mezt.
    write in : home, Windows11
    time : 2021.10.22
    using : Visual Studio Code
    from OI-wiki ：https://oi-wiki.org/graph/shortest-path/#floyd
    注明：这里只提供 Floyd 的核心代码，
         但是显然 Floyd 需要用邻接矩阵存，
         同时复杂度也惊人
*/
#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, f[101][101][101];
int main()
{
    /*
        我们定义一个数组 f[k][x][y]，表示只允许经过结点 1 到 k，
        结点 x 到结点 y 的最短路长度。
        其中的状态转移：
        f[k][x][y] = min(f[k - 1][x][y], f[k - 1][x][k] + f[k - 1][k][y])
        (f[k - 1][x][y]，为不经过 k 点的最短路径，而 f[k - 1][x][k] + f[k - 1][k][y]，
        为经过了 k 点的最短路)。
    */
    for (k = 1; k <= n; k++) 
    {
        for (x = 1; x <= n; x++) 
        {
            for (y = 1; y <= n; y++) 
            {
                f[k][x][y] = min(f[k - 1][x][y], f[k - 1][x][k] + f[k - 1][k][y]);
            }
        }
    }
    /*
    因为第一维对结果无影响，我们可以发现数组的第一维是可以省略的，
    于是可以直接改成 f[x][y] = min(f[x][y], f[x][k] + f[k][y])。
    */
    return 0;
}