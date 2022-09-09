#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unistd.h>
using namespace std;

const int Max = 1010;//边的数量
int num_of_node;//矿点数
int num_of_special_node;//特殊点数
int num_of_side;//建立边的总数
int new_num_of_side;//链式前向星边数

int head[Max * 10];
map<string, int> faster_find_player;//玩家 -> 编号快速 hash 映射
map<char, int> faster_find_node;//节点名字 -> 编号快速映射
int now_player_num;//目前玩家总数
int now_round_player_coin[Max];//本轮玩家得到的矿
double times = 1.00;//大后期矿藏涨价
int round_count = 0;//回合数计数
int num_of_expert, expert_bomb;//专家数量和拆除的炸弹
bool node_special[Max];//点是否为特殊点
int now_num_of_side;
vector<char> res;
int faster_find_next[Max][Max];

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
    int lnode, rnode;//存储该点所处边的左右顶点编号
}node[Max * 10];

void add(int u, int v, int num_of_node_on_the_side)
{
    e[new_num_of_side].from = u;
    e[new_num_of_side].to = v;
    e[new_num_of_side].next = head[u];//同节点下，该边的下一条边
    e[new_num_of_side].num_of_node_of_the_side = num_of_node_on_the_side;
    head[u] = new_num_of_side++;
}//链式前向星

void init()
{
    memset(head, -1, sizeof(head));
    for(int i = 0; i <= Max * 10 - 1; i++)
    {
        if(i % 10 == 0) node[i].bomb = 1;
    }
    for(int i = 1; i <= num_of_node; i++)
    {
        if(node[i].value == 0) node[i].value = 1;
    }
}

bool play(int now_pos, int certain_player)//0 -> left 1 -> right
{
    int now_left = node[now_pos].left, now_right = node[now_pos].right;
    //cout << now_left << ", " << now_right << endl;
    if(node[now_pos].bomb == 1)
    {
        return 0;
    }
    else
    {
        //cout << "jerjwjncrw" << 1 * times * node[now].value << ", " << now_player << endl;
        //if(node[now_pos].value == 0) cout << "这里已经被探索过了" << endl;
        now_round_player_coin[certain_player] += 1.0 * times * node[now_pos].value;
        player[certain_player].coin += 1.0 * times * node[now_pos].value;
        node[now_pos].value = 0;
    }
    return 1;
}

int normal(int now_pos, int certain_player, char choose_pos)
{
    bool flag = 1;
    if(node_special[now_pos] == 1) 
    {
       return -1;
    }
    else
    {
        if(faster_find_node[choose_pos] == node[now_pos].lnode)
        {
            if(node_special[now_pos] == 1) 
            {
                return -1;
            }
            now_pos = node[now_pos].left;
            if(play(now_pos, certain_player) == 0) 
            {
                flag = 0;
                return 0;
            }
            return now_pos;
        }
        else if(faster_find_node[choose_pos] == node[now_pos].rnode)
        {
            if(node_special[now_pos] == 1) 
            {
                return -1;
            }
            now_pos = node[now_pos].right;
            if(play(now_pos, certain_player) == 0) 
            {
                flag = 0;
                return 0;
            }
            return now_pos;
        }
        if(flag == 0)
        {
            return 0;
            //#TODO:剧情
        }
        
    }
    if(flag == 0)
    {
        //#TODO:剧情
        return 0;
    }
    return -2;
}

void find_near_special(int now_pos)
{
    res.clear();
    //cout << now_pos << ", " << head[now_pos] << endl;
    for(int i = head[now_pos]; i != -1; i = e[i].next)
    {
        //cout << i << ", " << e[i].to << ", ";
        res.push_back(node[e[i].to].name);
        cout << node[e[i].to].name << " ";
    }
    cout << endl;
}


int main()
{
    cout << "这么说，你是上帝？你要创造这样一个矿洞？好吧，请输入一共有多少个点。我满足你" << endl;
    cin >> num_of_node;
    cout << "好的，矿藏正在填充......请输入特殊点的个数，矿工们也需要十字路口，否则太单调；他们同样需要适时的奖励，平淡的人生，也需要有不同的火花" << endl;
    cin >> num_of_special_node;
    init();
    for(int i = 1; i <= num_of_special_node; i++)
    {
        char node_name;
        int node_num;
        double node_value;
        //#TODO:解决反复输出
        cout << "你是想添加特殊点吗？但我这里只有 A to Z，上帝先生，先给你这些。" << endl;
        //usleep(100000);
        cout << "....抑或是....一些金矿、银矿将代替灰黑的煤矿，成为矿洞中不可多得的宝物。想清楚啊，矿工们可能为其而争斗！" << endl;
        //usleep(100000);
        cout << "你还是来到了这一步？好吧，先输入节点的名字，如果，它不应当有一个名字，那就输入 ? 也行，这是它对世界小小的疑惑。" << endl;
        //usleep(100000);
        cin >> node_name;
        cout << "好了，节点没有一个像样的名字也不要紧，给它一个编号。即使是114514，它也会很开心的" << endl;
        //usleep(100000);
        cin >> node_num;
        if(node_name >= 'A' && node_name <= 'Z')
        {
            node_special[node_num] = 1;
            faster_find_node[node_name] = node_num;
        }
        cout << "它有特殊的价值吗？它是否十分贵重？或者，正如你我，平凡、渺小？" << endl;
        //sleep(5);
        cin >> node_value;
        //cout << node_name << ", " << node_num << ", " << node_value << endl;
        node[node_num].name = node_name;
        node[node_num].value = node_value;
    }
    cout << "特殊点在交织，交织成了最初的矿洞，现在，指画山河，试着将所有矿藏归类" << endl;
    cout << "先输入你想添加的边数" << endl;
    cin >> now_num_of_side;
    for(int i = 1; i <= now_num_of_side; i++)
    {
        //cout << "i" << i << ", " << now_num_of_side << endl;
        char begin_node, end_node;
        int sum_of_node, res_node[Max];
        cout << "起始点：";
        cin >> begin_node;
        cout << "终止点：";
        cin >> end_node;
        cout << "请输入这条边上所有的矿的个数（不算起、终点）" << endl;
        cin >> sum_of_node;
        add(faster_find_node[begin_node], faster_find_node[end_node], sum_of_node);
        add(faster_find_node[end_node], faster_find_node[begin_node], sum_of_node);

        cout << "能不能给出他们的编号呢？" << endl;
        for(int j = 1; j <= sum_of_node; j++)
        {
            cin >> res_node[j];
        }
        faster_find_next[faster_find_node[begin_node]][faster_find_node[end_node]] = res_node[1];
        faster_find_next[faster_find_node[end_node]][faster_find_node[begin_node]] = res_node[sum_of_node - 1];
        //cout << faster_find_node[begin_node] << ", " << faster_find_node[end_node] << endl;
        //node_next_node[faster_find_node[begin_node]].push_back(res_node[1]);
        //node_next_node[faster_find_node[end_node]].push_back(res_node[sum_of_node]);
        //分别记录一个节点出去的每条边的第一个节点编号
        for(int j = 1; j <= sum_of_node; j++)
        {
            int res_lnode = faster_find_node[begin_node], res_rnode = faster_find_node[end_node];
            //cout << res_node[j] << ", " << res_lnode << ", " << res_rnode << endl;
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
        //cout << "yes" << i << endl;
    }

    cout << "谢谢您，上帝先生，我相信，矿工们能进来了" << endl;

    /*
    for(int i = 1; i <= num_of_node; i++)
    {
        cout << i << ": " << node[i].left << ", " << node[i].right << ", " << node[i].lnode << ", " << node[i].rnode << endl;
    }
    */

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
                bool flag = 1;
                int now_pos = choose;
                cout << "吱呀....哐！您到达了一条矿洞，周围一片漆黑。提着灯，能辨别这个矿道的起点与终点" << endl;
                cout << node[node[now_pos].lnode].name << ", " << node[node[now_pos].rnode].name << endl;
                cout << "请输出您想选择的方向，每输入一次，都会向该方向走一步，然后反馈是否死亡（以及得到矿产的数量）：";
                char choose_pos;
                while(cin >> choose_pos)
                {
                    play(now_pos, certain_player);

                    bool flag = 0;
                    //cout << now_pos << ", " << certain_player << endl;
                    if(node_special[now_pos] == 1) 
                    {
                        //cout << "kkk" << endl;
                        flag = 1;
                        cout << "您抵达了一个特殊节点，" << node[now_pos].name << endl;
                        play(now_pos, certain_player);
                        
                        if(node[now_pos].bomb == 1) 
                        {
                            //#TODO:剧情以及优化
                            cout << "咝...什么声音？轰！矿洞顶在垮塌，你眼前一黑，额前一热。本轮收益：" << now_round_player_coin[certain_player] << endl;
                        }
                        else
                        {
                            cout << "还好，您没寄。" << "目前获得矿数：" << now_round_player_coin[certain_player] << endl;
                        }

                        cout << "周围有这些点:";
                        find_near_special(now_pos);
                        cout << "请你做出选择，往哪个方向：";
                        char res_pos;
                        cin >> res_pos;
                        now_pos = faster_find_next[now_pos][faster_find_node[res_pos]];
                        cout << now_pos << ", " << faster_find_node[res_pos] << endl;

                        play(now_pos, certain_player);

                        if(node[now_pos].bomb == 1) 
                        {
                            //#TODO:剧情以及优化
                            cout << "咝...什么声音？轰！矿洞顶在垮塌，你眼前一黑，额前一热。本轮收益：" << now_round_player_coin[certain_player] << endl;
                        }
                        else
                        {
                            cout << "还好，您没寄。" << "目前获得矿数：" << now_round_player_coin[certain_player] << endl;
                        }

                         //#TODO:走到特殊点行走处理，including bfs指令, [后期]tp, 探测器，灌水等功能开发，盾
                    }
                    if(flag == 0)
                    {
                        now_pos = normal(now_pos, certain_player, choose_pos);
                        if(node[now_pos].bomb == 1) 
                        {
                            //#TODO:剧情以及优化
                            cout << "咝...什么声音？轰！矿洞顶在垮塌，你眼前一黑，额前一热。本轮收益：" << now_round_player_coin[certain_player] << endl;
                        }
                        else
                        {
                            cout << "还好，您没寄。" << "目前获得矿数：" << now_round_player_coin[certain_player] << endl;
                        }
                    }
                }
                //#TODO:首先，要定位到这个点所处的边，如果是特殊点，提供所有邻接点。
                //#TODO:需要记录，走了几步，本轮得到矿的总量，得到矿的总量，maybe目前总排名，maybe当前局排名
            }
        }
    }
    return 0;
}