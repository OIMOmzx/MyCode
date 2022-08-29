class Solution 
{
public:
    const static int Max = 1000010;
    struct node
    {
        int from, to, next;
    }e[Max];

    int vis[Max], head[Max], cnt;
    
    void init()
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
    }

    void add(int u, int v)
    {
        e[cnt].from = u;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    bool dfs(int x, int color)
    {
        vis[x] = color;
        for(int i = head[x]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            //cout << x << ", " << v << endl;
            if(vis[v] == 0)
            {
                dfs(v, -color);
            }
            else if(vis[v] == color)
            {
                //cout << x << ", " << v;
                return 0;
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        if(n == 1) return 1;
        init();
        
        for(int i =x 0; i <= dislikes.size() - 1; i++)
        {
            //cout << dislikes[i][0] << ", " << dislikes[i][1] << endl;
            add(dislikes[i][0], dislikes[i][1]);
            add(dislikes[i][1], dislikes[i][0]);
        }
        //cout << "3fnrcwandijcn";
        for(int i = 1; i <= n; i++)
        {
            //cout << i << ", " << vis[i] << endl;
            if(vis[i] == 0) 
            {
                if(dfs(i, 1) == 0) return 0; 
            }
        }
        return 1;
        
    }
};