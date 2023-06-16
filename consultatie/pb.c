#include <stdio.h>

FILE *f;
void retine_solutia(int nr, int *x, int n)
{
    fprintf(f, "solutia numarul %d:", nr);
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", x[i]);
    fprintf(f, "\n");
}

int conditie_finala(int *x, int n)
{
    int i, s = 0;
    for (i = 0; i < n; i++)
        s += x[i];
    return s == 0;
}

// generare solutii

int generare_s(int *x, int n, int i, int a, int b, int nr)
{
    int j;
    if (i == n)
    {
        if (conditie_finala(x, n))
        {
            nr++;
            retine_solutia(nr, x, n);
        }
    }
    else
    {
        for (j = a; j <= b; j++)
        {
            x[i] = j;
            nr = generare_s(x, n, i + 1, a, b, nr);
        }
    }
    return nr;
}

int main()
{
    int n, a, b, x[100], nr = 0;
    printf("n=");
    scanf("%d", &n);
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    f = fopen("rezultate.txt", "w");
    nr = generare_s(x, n, 0, a, b, 0);
    printf("numarul de solutii este %d\n", nr);
    return 0;
}