#include <stdio.h>
#include <stdlib.h>

int **times;
int **aux;

int compare(const void *pa, const void *pb)
{
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    if (a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}
int main()
{
    int act;
    int s, e;
    scanf("%d", &act);
    times = (int **)malloc(sizeof(int *) * act);
    aux = (int **)malloc(sizeof(int *) * act);
    for (int i = 0; i < act; i++)
    {
        times[i] = (int *)malloc(sizeof(int) * 2);
        aux[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &s, &e);
        times[i][0] = s;
        times[i][1] = e;
    }

    qsort(times, act, sizeof(int) * 2, compare);
    aux[0][0] = times[0][0];
    aux[0][1] = times[0][1];

    int ind = 1;
    for (int i = 1; i < act; i++)
    {
        if (times[i][0] > aux[ind - 1][0] && times[i][1] < aux[ind - 1][1])
        {
            aux[ind - 1][0] = times[i][0];
            aux[ind - 1][1] = times[i][1];
        }
        else if (times[i][0] >= aux[ind - 1][1])
        {
            aux[ind][0] = times[i][0];
            aux[ind][1] = times[i][1];
            ind++;
        }
    }
    printf("%d\n", ind);

    free(times);

    return 0;
}
