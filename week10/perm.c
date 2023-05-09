// pb permutarilor - var cu ratie

#include <stdio.h>
#include <stdlib.h>

// funct de validare
// IN : v[] - permutare, i - nivelul curent
// OUT: 1 - daca permutarea este valida, 0 - altfel
int valid(int v[], int i)
{
    int j;
    for (j = 0; j < i; j++)
        if (v[i] == v[j])
            return 0;
    return 1;
}

// funct retinere solutie
// IN : num - nr solutie, v[] - permutare completa, n - nr elemente
// OUT: afisare

void afis(int num, int n, int v[])
{
    int i;
    printf("\nSolutia nr.%d: ", num);
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

// IN: dim permutarii
// out: nr- nr de solutii (rez intors prin numele functiei)

int permutari(int n)
{
    int *p; // permutare de construire, sol partiala
    int i, am, nr = 0;
    p = (int *)malloc(n * sizeof(int));
    i = 0;    // nivelul curent
    p[0] = 0; // initializare val pt primul nivel (prima val(1) - ratia(1))
    while (i >= 0)
    {
        am = 0; // am - semafor
        while (p[i] < n && !am)
        {
            p[i]++; // incercare val noua
            if (valid(p, i))
                am = 1; // am gasit o val buna
        }
        if (!am)
        {
            i--; // se revine la nivelul anterior fiind consumate toate variantele pt nivelul curent
        }
        else if (i == n - 1)
        {
            nr++;
            afis(nr, n, p); // am pus un elem valid si am construit o solutie completa
        }
        else
        {
            i++;
            p[i] = 0; // cresc nivelul si initializez val pt noul nivel
        }
    }
    free(p);
    return nr;
}

int main()
{
    int v[10], n, nr;
    scanf("%d", &n);
    nr = permutari(n);
    printf("%d", nr);
    return 0;
}