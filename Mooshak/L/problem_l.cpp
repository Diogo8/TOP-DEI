#include <stdio.h>
#include <vector>

#define N 600
#define C 1000
#define O 250

using namespace std;
vector<pair<int, int>> obj;

int total_obj, max_obj, max_money;

int knapsack(int i, int c, int w)
{
    if (i == 0 || w == 0)
    {
        return 0;
    }
    else if (obj[i - 1].second > w || c == 0)
    {
        return knapsack(i - 1, c, w);
    }
    else
    {
        return max(knapsack(i - 1, c, w), obj[i - 1].first + knapsack(i - 1, c - 1, w - obj[i - 1].second));
    }
}

int main()
{

    int m, n;

    scanf("%d", &total_obj);
    scanf("%d", &max_obj);
    scanf("%d", &max_money);

    for (int i = 0; i < total_obj; i++)
    {
        scanf("%d %d", &m, &n);
        obj.push_back(make_pair(m, n));
    }

    printf("%d\n", knapsack(total_obj, max_obj, max_money));
    return 0;
}
