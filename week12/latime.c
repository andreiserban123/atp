// n = 7
// m = 10
// vfp = 1
// vezi graf in fisier
#include <stdio.h>

int a[20][20]; // mat de adicacenta trebuie construita
int n, m, vfp;
int viz[20];

// viz[] - vector de vizitare(0/1)
int coada[20], p, u;
// coada[] - rezultat final
int i, j, el, pl, x, y;
// n - nr vf
// m - nr muchii
// el - element curent
// x, y -variabile ajutatoare
// pl - vf de plecare

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
    viz[pl] = 1;
    coada[1] = pl;
    p = 1;
    u = 1;
    while (p <= u)
    {
        el = coada[p];
        p++;
        for (i = 1; i <= n; i++)
        {
            if (a[el][i] == 1 && viz[i] == 0)
            {
                u++;
                coada[u] = i;
                viz[i] = 1;
            }
        }
    }
    printf("\nParcurgere in latime: ");
    for (i = 1; i <= u; i++)
    {
        printf("%d ", coada[i]);
    }
    return 0;
}