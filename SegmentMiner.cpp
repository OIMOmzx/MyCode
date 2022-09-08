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
map<char, int> faster_find_node;//节点名字 -> 编号快速映射
int now_player_num;//目前玩家总数
int now_round_player_coin[Max];//本轮玩家得到的矿
double times = 1.00;//大后期矿藏涨价
int round_count = 0;//回合数计数
int num_of_expert, expert_bomb;//专家数量和拆除的炸弹
bool node_special[Max];//点是否为特殊点

struct miner
{
    int num;//编号，目前有些鸡肋，但感觉排序的时候用得到
    int coin;//矿的总数
    string name;//玩家姓名
}player[Max];

struct side
{
    char from, to;//字面意思
    int next;//阅读代码者不用了解
    int num_of_node_of_the_side;//这条边上一共有多少节点（Attention !!! 不算两头的特殊点）
}e[Max];//边集数组

struct nodes
{
    char name;
    double value;
    bool bomb;
    int left, right;//存储该点的左右序号？暂定
    char lnode, rnode;//存储该点所处边的左右顶点编号
}node[Max * 10];

void add(char u, char v, int num_of_node_on_the_side)
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

bool play(bool option, int now, int now_player)//0 -> left 1 -> right
{
    int now_left = node[now].left, now_right = node[now].right;
    if(node[now].bomb == 1)
    {
        return 0;
    }
    else
    {
        now_round_player_coin[now_player] += 1 * times * node[now].value;
        player[now_player].coin += 1 * times * node[now].value;
    }
    return 1;
}

int normal(int now_pos, int certain_player)
{
    bool flag = 1;
    if(node_special[now_pos] == 1) 
    {
       return -1;
    }
    else
    {
        cout << "吱呀....哐！您到达了一条矿洞，周围一片漆黑。提着灯，能辨别这个矿道的起点与终点" << endl;
        cout << node[now_pos].lnode << ", " << node[now_pos].rnode << endl;
        char choose_pos;
        cout << "请输出您想选择的方向，每输入一次，都会向该方向走一步，然后反馈是否死亡（以及得到矿产的数量）：";
        while(cin >> choose_pos)
        {
            if(choose_pos == node[now_pos].lnode)
            {
                if(node_special[now_pos] == 1) 
                {
                    return -1;
                }
                if(play(0, now_pos, certain_player) == 0) 
                {
                    flag = 0;
                    return 0;
                }
                now_pos = node[now_pos].left;
                normal(now_pos, certain_player);
            }
            else if(choose_pos == node[now_pos].rnode)
            {
                if(node_special[now_pos] == 1) 
                {
                    return now_pos;
                }
                if(play(1, now_pos, certain_player) == 0) 
                {
                    flag = 0;
                    break;
                }
                now_pos = node[now_pos].right;
                normal(now_pos, certain_player);
            }
            if(flag == 0)
            {
                return 0;
                //#TODO:剧情
                break;
            }
        }
    }
    if(flag == 0)
    {
        //#TODO:剧情
        return 0;
    }
    return -2;
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
        cout << "好了，节点没有一个像样的名字也不要紧，给它一个编号。即使是114514，它也会很开心的" << endl;
        cin >> node_num;
        if(node_name >= 'A' && node_name <= 'Z')
        {
            node_special[node_num] = 1;
            faster_find_node[node_name] = node_num;
        }
        cout << "它有特殊的价值吗？它是否十分贵重？或者，正如你我，平凡、渺小？" << endl;
        cin >> node_value;
        node[node_num].name = node_name;
        node[node_num].value = node_value;
    }
    cout << "特殊点在交织，交织成了最初的矿洞，现在，指画山河，试着将所有矿藏归类" << endl;
    cout << "先输入你想添加的边数" << endl;
    cin >> num_of_side;
    for(int i = 1; i <= num_of_side; i++)
    {
        char begin_node, end_node;
        int sum_of_node, res_node[Max];
        cout << "起始点：";
        cin >> begin_node;
        cout << endl;
        cout << "终止点：";
        cin >> end_node;
        cout << "请输入这条边上所有的矿的个数（不算起、终点）" << endl;
        cin >> sum_of_node;
        add(begin_node, end_node, sum_of_node);
        for(int j = 1; j <= sum_of_node; j++)
        {
            cin >> res_node[j];
        }
        for(int j = 1; j <= sum_of_node; j++)
        {
            int res_lnode = faster_find_node[begin_node], res_rnode = faster_find_node[end_node];
            node[res_node[j]].lnode = res_lnode, node[res_node[j]].rnode = res_rnode;
            if(j == 1)//该边的第一个节点
            {
                node[res_node[j]].left = res_lnode;
                node[res_node[j]].right = res_node[j + 1];
            }
            else if(j == sum_of_node)//该边最后一个节点
            {
                node[res_node[j]].left = res_node[j - 1];
                node[res_node[j]].right = res_rnode;
            }
            else//正常情况
            {
                node[res_node[j]].left = res_node[j - 1];
                node[res_node[j]].right = res_node[j + 1];
            }
        }
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

            cout << "你想选择哪一个节点？别害怕，即使遭遇不测，我相信您也能再次回到这里。" << endl;
            int choose;
            cin >> choose;
            //#TODO:修理一下内容
            if(node[choose].bomb == 1)
            {
                cout << "不幸的是，您踩到了雷。眼前的一切在消散。您意识散去之前，看到了闪烁的光影，与急促的喊叫。" << endl;
                player[certain_player].coin += 0;
                now_round_player_coin[certain_player] = 0;
            }
            else
            {
                //#TODO:补充while
                bool flag = 1;
                int now_pos = choose;
                while(1)
                {
                    if(node_special[now_pos] == 1) 
                    {
                        cout << "您抵达了一个特殊节点，" << node[now_pos].name << endl;
                         //#TODO:走到特殊点行走处理，including bfs指令, [后期]tp, 探测器，灌水等功能开发
                    }
                }
                //#TODO:首先，要定位到这个点所处的边，如果是特殊点，提供所有邻接点。
                //#TODO:需要记录，走了几步，本轮得到矿的总量，得到矿的总量，maybe目前总排名，maybe当前局排名
            }
        }
    }
    return 0;
}