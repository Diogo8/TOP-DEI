#include <stdio.h>
#include <vector>
struct graph
{
    std::vector<int> adj;
    bool visited;
};

graph *g;
int max_node;
int count = -1;
void dfs(int ind, int c)
{

    g[ind].visited = true;

    c++;
    for (int i = 0; i < static_cast<int>(g[ind].adj.size()); i++)
    {

        if (!g[g[ind].adj[i]].visited)
        {
            if (c > count)
            {
                count = c;
                max_node = g[ind].adj[i];
            }
            dfs(g[ind].adj[i], c);
        }
    }
}

int main()
{
    int n, m;
    int k;
    scanf("%d", &k);
    g = new graph[1000000];
    while (scanf("%d %d", &n, &m) == 2)
    {

        g[n].adj.push_back(m);
        g[m].adj.push_back(n);
        g[n].visited = false;
        g[m].visited = false;
    }
    dfs(m, 0);
    for (int i = 0; i < 1000000; i++)
        g[i].visited = false;
    dfs(max_node, 0);
    printf("%d\n", count);

    return 0;
}
