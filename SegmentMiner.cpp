#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

const int Max = 110;//边的数量
int num_of_node;//矿点数
int num_of_special_node;//特殊点数
int num_of_side;//建立边的总数

int head[Max * 10];
map<string, int> faster_find_player;//玩家 -> 编号快速 hash 映射
int now_player_num;//目前玩家总数
int now_round_player_coin[Max];
double times = 1.00;//大后期矿藏涨价
int round_count = 0;//回合数计数
int num_of_expert, expert_bomb;//专家数量和拆除的炸弹

struct miner
{
    int num;//编号，目前有些鸡肋，但感觉排序的时候用得到
    int coin;//矿的总数
    string name;//玩家姓名
}player[Max];

struct side
{
    int from, to;//字面意思
    int next;//阅读代码者不用了解
    int num_of_node_of_the_side;//这条边上一共有多少节点（Attention !!! 不算两头的特殊点）
}e[Max];//边集数组

struct nodes
{
    char name;
    double value;
    bool bomb;
    int left, right;//存储该点的左右序号？暂定
    int lnode, rnode;//存储该点所处边的左右顶点
}node[Max * 10];

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
        if(i % 10 == 0) node[i].bomb = 1;
    }
}

int main()
{
    cout << "这么说，你是上帝？你要创造这样一个矿洞？好吧，请输入一共有多少个点。我满足你" << endl;
    cin >> num_of_node;
    cout << "好的，矿藏正在填充......请输入特殊点的个数，矿工们也需要十字路口，否则太单调；他们同样需要适时的奖励，平淡的人生，也需要有不同的火花" << endl;
    cin >> num_of_special_node;
    for(int i = 1; i <= num_of_special_node; i++)
    {
        char node_name, node_num;
        double node_value;
        cout << "你是想添加特殊点吗？但我这里只有 A to Z，上帝先生，先给你这些。" << endl;
        cout << "....抑或是....一些金矿、银矿将代替灰黑的煤矿，成为矿洞中不可多得的宝物。想清楚啊，矿工们可能为其而争斗！" << endl;
        cout << "你还是来到了这一步？好吧，先输入节点的名字，如果，它不应当有一个名字，那就输入 ? 也行，这是它对世界小小的疑惑。" << endl;
        cin >> node_name;
        cout << "好了，节点没有一个像样的名字也不要紧，给它一个编号。即使是114514，它也会很开心的" << endl
        cin >> node_num;
        cout << "它有特殊的价值吗？它是否十分贵重？或者，正如你我，平凡、渺小？" << endl;
        cin >> node_value;
        node[node_num].name = node_name;
        node[node_num].value = node_value;
    }
    cout << "谢谢您，上帝先生，我相信，矿工们能进来了" << endl;

    while(1)//由许多轮组成的本场游戏
    {
        //#TODO:待补充结束条件
        round_count++;
        cout << "Round " << round_count << " begins !!" << endl;
        cout << "有拆弹专家吗？几位？" << endl;
        cin >> num_of_expert;
        if(num_of_expert != 0)
        {
            cout << "他们要拆除什么编号的炸弹" << endl;
            for(int i = 1; i <= num_of_expert; i++)
            {
                cin >> expert_bomb;
                node[expert_bomb].bomb = 0;
            }
        }

        while(1)//不限参与人数
        {
            memset(now_round_player_coin, 0, sizeof(now_round_player_coin));
            string player_name;
            cout << "你是....新来的矿工？这里很危险" << endl;
            cout << "报一下你的名字吧，我不记得你了，太多矿工来过这里，太多人离去，太多人就死在这里.....你一定要想起自己第一次来的时候的姓名，不然说错的话，矿洞就会遗忘你...." << endl;
            cin >> player_name;
            if(faster_find_player[player_name] == 0)//新建用户
            {
                ++now_player_num;
                cout << "欢迎" << player_name << "成为第" << now_player_num << "位矿工!!" << endl;
                player[now_player_num].num = now_player_num;
                player[now_player_num].name = player_name;
                faster_find_player[player_name] = now_player_num;
                cout << "未来的生活，一起加油！" << endl;
            }

            int certain_player = faster_find_player[player_name];//在探险的矿工

            int choose;
            cin >> choose;
            cout << "你想选择哪一个节点？别害怕，即使遭遇不测，我相信您也能再次回到这里。" << endl;
            if(node[choose].bomb == 1)
            {
                cout << "不幸的是，您踩到了雷。眼前的一切在消散。您意识散去之前，看到了闪烁的光影，与急促的喊叫。" << endl;
                player[certain_player].coin += 0;
                now_round_player_coin[certain_player] = 0;
            }
            else
            {
                //#TODO:首先，要定位到这个点所处的边，如果是特殊点，提供所有邻接点。
                //#TODO:需要记录，走了几步，本轮得到矿的总量，得到矿的总量，maybe目前总排名，maybe当前局排名
                //#TODO:走到特殊点行走处理，including bfs指令, [后期]tp, 探测器，灌水等功能开发
            }
        }
    }
    return 0;
}