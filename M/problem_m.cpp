#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <climits>
struct graph
{

    std::vector<int> dest;
    int weight[1000];
};

int n, m;

void wormholes(graph *g)
{
    int aux[n];
    for (int i = 0; i < n; i++)
    {
        aux[i] = INT_MAX;
    }
    aux[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < static_cast<int>(g[j].dest.size()); k++)
            {
                int dist = g[j].weight[g[j].dest[k]];
                if (aux[g[j].dest[k]] > dist + aux[j])
                {
                    aux[g[j].dest[k]] = dist + aux[j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < static_cast<int>(g[i].dest.size()); j++)
        {
            int dist = g[i].weight[g[i].dest[j]];
            if (aux[g[i].dest[j]] > dist + aux[i])
            {
                printf("possible\n");
                return;
            }
        }
    }
    printf("not possible\n");
}
int main()
{

    int cases;
    int star1, star2, dist;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        scanf("%d %d", &n, &m);
        graph *g = new graph[1000];
        for (int j = 0; j < m; j++)
        {
            scanf("%d %d %d", &star1, &star2, &dist);

            g[star1].dest.push_back(star2);
            g[star1].weight[star2] = dist;
        }
        wormholes(g);
    }

    return 0;
}
