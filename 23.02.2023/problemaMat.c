// inmultim un scalar pt matricea noastra
#include <stdio.h>
#include <malloc.h>
int **alocM(int **mat, int n, int m)
{
    mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mat[i] = (int *)malloc(m * sizeof(int));
    return mat;
}

void citireM(int **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
}
void afisM(int **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
void dezalocM(int **mat, int n)
{
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

void inmultire(int **mat, int n, int m, int *scalar)
{
    printf("scalar = ");
    scanf("%d", scalar);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] *= (*scalar);
}
int main()
{
    int n, m, **mat, scalar;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    mat = alocM(mat, n, m);
    printf("mat = ");
    citireM(mat, n, m);
    printf("\nmat = ");
    afisM(mat, n, m);
    inmultire(mat, n, m, &scalar);
    printf("\nmat = ");
    afisM(mat, n, m);
    dezalocM(mat, n);
    return 0;
}