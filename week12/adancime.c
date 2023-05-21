// n = 7
// m = 10
// vfp = 1
// vezi graf in fisier
#include <stdio.h>

int a[20][20]; // mat de adicacenta trebuie construita
int n, m, vfp;
// viz[] - vector de vizitare(0/1)
int viz[20];

int i, j, pl, x, y;
// n - nr vf
// m - nr muchii
// x, y -variabile ajutatoare
// pl - vf de plecare

void parcurgere_adancime(int pl)
{
    printf("%d ", pl);
    viz[pl] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[pl][i] == 1 && viz[i] == 0)
        {
            parcurgere_adancime(i);
        }
    }
}

int main()
{
    // citire graf
    printf("\nn = ");
    scanf("%d", &n);
    printf("\nm = ");
    scanf("%d", &m);
    // construire matrice de adiacenta
    for (i = 1; i <= m; i++)
    {
        printf("\nMuchia %d: ", i);
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        viz[i] = 0; // initializare vector de vizitare
    }
    printf("\nvf de plecare = ");
    scanf("%d", &pl);
    printf("\nParcurgere in adancime: ");
    parcurgere_adancime(pl);

    return 0;
}