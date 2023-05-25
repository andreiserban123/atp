#include <stdio.h>
#include <stdlib.h>

#define VAL 999
int i, j, k, a, b, u, v, n, mA = 1; // mA - muchii arbore
int min, costmin = 0, cost[9][9], parinte[9];
// union - find

int gaseste(int i)
{
    while (parinte[i])
        i = parinte[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parinte[j] = i;
        return 1;
    }
    return 0;
}
int main()
{
    printf("Implementare algoritm Kruskal\n");
    printf("Dati numarul de noduri:");
    scanf("%d", &n);
    printf("Introduceti matricea de costuri (se va pune valoarea zero unde nu exista muchie)\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = VAL;
        }

    printf("\n");

    printf("Matricea costurilor este:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", cost[i][j]);
        printf("\n");
    }

    printf("\n");

    printf("Arborele de cost minim este:\n");
    while (mA < n)
    {
        for (i = 1, min = VAL; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = gaseste(u);
        v = gaseste(v);
        if (uni(u, v))
        {
            // Afisare muchii
            printf("%d edge (%d,%d) =%d\n", mA++, a, b, min);
            costmin += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    // Afisare cost minim arbore
    printf("\n\tCost minim = %d\n", costmin);
    return 0;
}
