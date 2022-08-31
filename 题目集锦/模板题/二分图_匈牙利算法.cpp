#include <iostream>
using namespace std;

const int Max = 1000010;
int cnt = 0, head[Max];
bool vis[Max], match[Max];

struct node
{
    int from, to, next;
}e[Max];

void add(int u, int v)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

bool find(int u)
{
    for(int i = head[u]; i != -1; i = e[i].next)
    {
        int v = e[i].to;
        if(!vis[v])
        {
            vis[v] = 1;
            if(!match[v] || find(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

void init()
{
    cnt = 0;
    
}

int main()
{
    memset(head, -1, sizeof(head));
    return 0;
}