#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int Max = 110;//边的数量
int num_of_node;//矿点数
int num_of_special_node;//特殊点数
int num_of_side;//建立边的总数

int head[Max * 10];
int value_of_all_node[Max * 10];
int if_bomb_of_all_node[Max * 10];
char name_of_all_node[Max * 10];//每个节点的名字，用桶数组形式存储
bool if_special_of_all_node[Max * 10];//这个编号的点，是否是特殊点

struct node
{
    int from, to;//字面意思
    int next;//不用了解
    int num_of_node_of_the_side;//这条边上一共有多少节点（Attention !!! 不算两头的特殊点）
}e[Max];//边集数组

void add(int u, int v, int num_of_node_on_the_side)
{
    e[num_of_side].from = u;
    e[num_of_side].to = v;
    e[num_of_side].next = head[u];//同节点下，该边的下一条边
    head[u] = num_of_side++;
}//链式前向星

void init()
{
    memset(head, -1, sizeof(head));
    for(int i = 0; i <= Max * 10 - 1; i++)
    {
        if(i % 10 == 0) if_bomb_of_all_node[i] = 1;
    }
}

int main()
{
    cout << "请输入一共有多少个点" << endl;
    cin >> num_of_node;
    cout << "请输入特殊点的个数" << endl;
    cin >> num_of_special_node;
    for(int i = 1; i <= num_of_special_node; i++)
    {
        char name, num;
        cout << "先输入节点的名字,例如A,B,这种（由于C++的限制，目前最高支持26个特殊点，除非你愿意看到像#这样的字符成为特殊点）" << endl;
        cout << "然后输入节点的编号";
        cin >> name >> num;
        name_of_all_node[num] = name;
        if_special_of_all_node[num] = name;
    }
    while(1)//由许多轮组成的本场游戏
    {
        //#TODO:待补充结束条件
        while(1)//不限参与人数
        {
            //#TODO:玩家身份认证
            int choose;
            cout << "选择哪一个节点" << endl;
            if(if_bomb_of_all_node[choose] == 1)
            {
                //#TODO:开局死亡提醒；
                //cout << 
            }
            //#TODO:需要记录，走了几步，本轮得到矿的总量，得到矿的总量，maybe目前总排名，maybe当前局排名
            //#TODO:走到特殊点行走处理，including bfs指令, [后期]tp, 探测器，灌水等功能开发
        }
    }
    return 0;
}