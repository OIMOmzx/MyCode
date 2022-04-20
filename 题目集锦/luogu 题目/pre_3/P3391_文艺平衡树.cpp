#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int Max = 1000010;
const int inf = 0x3f3f3f3f;

struct node
{
    int fa;
    int son[2];
    int val;
    int minn, size, add_lzt, rev_lzt; 
}tree[Max];

int n, cnt, root, t;
int a[Max];
int q, l, r, k;
char type[10];

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


void Update(int x)
{
    tree[x].minn = tree[x].val;
    tree[x].size = 1;
    if(tree[x].son[0])
    {
        tree[x].size += tree[tree[x].son[0]].size;
        tree[x].minn = min(tree[x].minn, tree[tree[x].son[0]].minn);
    }
    if(tree[x].son[1])
    {
        tree[x].size += tree[tree[x].son[1]].size;
        tree[x].minn = min(tree[x].minn, tree[tree[x].son[1]].minn);
    }
}

void Pushdown(int x)
{
    if(tree[x].rev_lzt)
    {
        tree[x].rev_lzt ^= 1;
        swap(tree[x].son[0], tree[x].son[1]);
        if(tree[x].son[0])
        {
            tree[tree[x].son[0]].rev_lzt ^= 1;
        }
        if(tree[x].son[1])
        {
            tree[tree[x].son[1]].rev_lzt ^= 1;
        }
    }
    if(tree[x].add_lzt)
    {
        if(tree[x].son[0])
        {
            tree[tree[x].son[0]].add_lzt += tree[x].add_lzt;
            tree[tree[x].son[0]].val += tree[x].add_lzt;
            tree[tree[x].son[0]].minn += tree[x].add_lzt;
        }
        if(tree[x].son[1])
        {
            tree[tree[x].son[1]].add_lzt += tree[x].add_lzt;
            tree[tree[x].son[1]].val += tree[x].add_lzt;
            tree[tree[x].son[1]].minn += tree[x].add_lzt;
        }
        tree[x].add_lzt = 0;
    }
}

int New(int father, int val)
{
    tree[++cnt].fa = father;
    tree[cnt].val = val;
    tree[cnt].minn = val;
    tree[cnt].size = 1;
    tree[cnt].add_lzt = tree[cnt].rev_lzt = 0;
    tree[cnt].son[0] = tree[cnt].son[1] = 0;
    return cnt;
}

void Rotate(int x)
{
    Pushdown(x);
    int y = tree[x].fa;
    int z = tree[y].fa;
    int c = (tree[y].son[0] == x); // 1 : x 是 y 的左孩子（右旋） 0 : x 是 y 的右孩子（左旋）

    tree[y].son[!c] = tree[x].son[c];
    tree[tree[x].son[c]].fa = y;

    tree[x].fa = z;
    if(z)
    {
        tree[z].son[tree[z].son[1] == y] = x;
    }

    tree[x].son[c] = y;
    tree[y].fa = x;

    Update(y);
    Update(x);
}

void Splay(int x, int goal)
{
    //cout << "iqqopee" << endl;
    while(tree[x].fa != goal)
    {
        int y = tree[x].fa, z = tree[y].fa;
        if(z != goal)
        {
            (tree[z].son[0] == y) ^ (tree[y].son[0] == x) ? Rotate(x) : Rotate(y);//x, y, z 在一条链下，要先把 y 翻开。
        }
        Rotate(x);
    }
    if(!goal) root = x;
}

void print(int rt)
{
    //cout << "ewfd";
    if(!rt) return;
    if(tree[rt].son[0])
    {
        print(tree[rt].son[0]);
    }
    if(tree[rt].val != inf && tree[rt].val != -inf)
    {
        cout << tree[rt].val << " ";
    }
    if(tree[rt].son[1]) 
    {
        print(tree[rt].son[1]);
    }
}

int Findk(int x, int val)
{
    while(1)
    {
        Pushdown(x);
        int sn = tree[x].son[0] ? tree[tree[x].son[0]].size + 1 : 1;
        if(val == sn) 
        {
            return x;
        }
        if(val > sn)
        {
            val -= sn;
            x = tree[x].son[1];
        }
        else
        {
            x = tree[x].son[0];
        }
    }
}

void Insert(int pos, int val)
{
    int x = Findk(root, pos), y = Findk(root, pos + 1);
    Splay(x, 0), Splay(y, x);
    tree[y].son[0] = New(y, val);
    Update(y), Update(x);
}

void Delete(int pos)
{
    int x = Findk(root, pos - 1), y = Findk(root, pos + 1);
    Splay(x, 0), Splay(y, x);
    tree[y].son[0] = 0;
    Update(y), Update(x);
}

int Min(int l, int r)
{
    //cout << "testd" << endl; 
    int x = Findk(root, l - 1), y = Findk(root, r + 1);
    //cout << "efuh" << endl;
    Splay(x, 0), Splay(y, x);
    //cout << "eeee " << endl;
    //cout << tree[tree[y].son[0]].minn;
    return tree[tree[y].son[0]].minn;
}

void Build(int l, int r, int &t, int fa)
{
    if(l > r) return;
    int mid = (l + r) >> 1;
    t =  New(fa, a[mid]);
    Build(l, mid - 1, tree[t].son[0], t);
    Build(mid + 1, r, tree[t].son[1], t);
    Update(t);
}

void init()
{
    cnt = root = 0;
    tree[0].son[0] = tree[0].son[1] = 0;
    root = New(0, -inf);
    tree[root].son[1] = New(root, inf);
    tree[root].size = 2;
    Build(1, n, tree[tree[root].son[1]].son[0], tree[root].son[1]);
    Update(tree[root].son[1]);
    Update(root);
}

void Add(int l, int r, int val)
{
    int x = Findk(root, l - 1), y = Findk(root, r + 1);
    Splay(x, 0), Splay(y, x);
    tree[tree[y].son[0]].val += val;
    tree[tree[y].son[0]].minn += val;
    tree[tree[y].son[0]].add_lzt += val;
    Update(y), Update(x);
}

void Reverse(int l, int r)
{
    int x = Findk(root, l - 1), y = Findk(root, r + 1);
    Splay(x, 0), Splay(y, x);
    tree[tree[y].son[0]].rev_lzt ^= 1;
}

void Revolve(int l, int r, int T)
{
    T %= (r - l + 1);
    if(T == 0) return;
    int x = Findk(root, r - T), y = Findk(root, r + 1);
    Splay(x, 0), Splay(y, x);
    int tmp = tree[y].son[0];
    tree[y].son[0] = 0;
    Update(y), Update(x);
    x = Findk(root, l - 1), y = Findk(root, l);
    Splay(x, 0), Splay(y, x);
    tree[y].son[0] = tmp;
    tree[tmp].fa = y;
    Update(y), Update(x);
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    //cout << a[1] << endl;
    init();
    int m;
    m = read();
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        Reverse(++a, ++b);
    }
    print(root);
    return 0;
}