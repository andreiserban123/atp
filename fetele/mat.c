#include <stdio.h>

int main()
{
    int mat[100][100], n, i, j;
    // read mat
    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", mat[i][i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mat[i][n - i - 1]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}