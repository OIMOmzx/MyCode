### Part 0 

[原题传送门](https://www.luogu.com.cn/problem/P8090)

希望能够过申，谢谢～

### Part 1 题意

原题会给出两个 $3 \times 3$ 的方阵，第一个是奶牛猜测的，第二个是正确的方阵，要求我们输出绿色和黄色高亮显示的方格的数量。

1. 首先看到原题对绿色高亮的描述：

	> 猜测的某些方格可能是正确的，这些方格以绿色高亮显示。

	所以只需输出两个方阵中对应位置相符的数量即可。

2. 我们再看到题目对黄色高亮的描述：

	> 另一些方格可能填入了品种正确但位置错误的奶牛，这些以黄色高亮显示。

	所以黄色高亮就是这个字母在两个方阵中都出现了，但是没有做到对应位置相符的数量
    
### Part 2 解题

我的模拟思路可能较为清奇，是这样的：

$ a $ 和 $ b $ 两个数组用来记录 $ mp1 $ 和 $ mp2 $ 中 $ A $ 到 $ Z $ 字母的个数，同时用 $ c $ 数组记录绿色高亮的是什么字母，有多少个。最终按字母序扫一遍三个数组，用这个字母在两个方阵中都出现了的个数，即 ```min(a[i], b[i])``` 减去做到对应位置相符的数量，即 ```c[i]```。

话不多说，上代码。

### Part 3 代码


```cpp
/*
作者: mzx
题目: USACO, Jan., Bronze, T1 Herdle
算法: 
日期: 2022.1.29
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

int a[27], b[27], c[27];
char mp1[4][4], mp2[4][4];
int ans1, ans2;

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
    ofstream fout("Herdle.out");
    ifstream fin("Herdle.in");
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> mp1[i][j];
            a[mp1[i][j] - 'A' + 1]++;
        }
    }
    for(int i = 1; i <= 3; i ++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> mp2[i][j];
            b[mp2[i][j] - 'A' + 1]++;
        }
    }//以上是读入与记录部分
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(mp1[i][j] == mp2[i][j])
            {
                ans1++;//绿色高亮记录
                c[mp1[i][j] - 'A' + 1]++;//每一个字母分别记了多少次绿色高亮
            }
        }
    }
    for(int i = 1; i <= 26; i++)
    {
        if(a[i] != 0 && b[i] != 0)
        {
            ans2 += min(a[i], b[i]) - c[i];//字母出现的个数减去这个字母被记绿色高亮的次数
        }
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}

```

### Part 4 结果

[O2, 40ms](https://www.luogu.com.cn/record/68586082)