#include <bits/stdc++.h>
using namespace std;

const int Max = 10000010;
int head[Max], idx;
int depth[Max], fa[Max][22], graph[Max];
int n, m, t, x, y;

struct node
{
    int to;
    int next;
}e[Max];
void add(int x, int y)
{
    e[++idx].to = y;
	e[idx].next = head[x];
	head[x] = idx;
}//不带权值的链式前向星
/*
    附：从 Dijkstra 里面弄下来的带权值的链式前向星
    void add(int x, int y, int z)
    {
        // y 是新的一条出边，z 是权值。
        edge[++idx].to = y;
        edge[idx].w = z;
        edge[idx].next = head[x];
        head[x] = idx;
    }
*/
void dfs(int now, int father)
{
    fa[now][0] = father;
    depth[now] = depth[father] + 1;
    for(int i = 1; i <= graph[depth[now]]; ++i)
    {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    for(int i = head[now]; i; i = e[i].next)
    {
		if(e[i].to != father) dfs(e[i].to, now);
    }
}

int LCA(int x, int y)
{
    if(depth[x] < depth[y]) swap(x, y);
    while(depth[x] > depth[y])
    {
        x = fa[x][graph[depth[x] - depth[y]] - 1];
        //将 x 和 y 提升到同一高度
    }
    if(x == y) return x;
    for(int k = graph[depth[x]] - 1; k >= 0; --k)
    {
		if(fa[x][k] != fa[y][k])
        {
			x = fa[x][k], y = fa[y][k];
        }
    }
	return fa[x][0];
}
int main() 
{
    cin >> n >> m >> t;
	for(int i = 1; i <= n - 1; i++) 
    { 
        cin >> x >> y;
		add(x, y), add(y, x);
	}
	for(int i = 1; i <= n; i++)
    {
		graph[i] = graph[i - 1] + (1 << graph[i - 1] == i);
    }
	dfs(t, 0);
	for(int i = 1; i <= m; i++) 
    {
		cin >> x >> y;
		cout << LCA(x, y) << endl;
	}
	return 0;
}
