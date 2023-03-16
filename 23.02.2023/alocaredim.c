// 2. citire alocare dinamica si afisare a vectorului
#include <stdio.h>
#include <malloc.h>

int *alocV(int *v, int n)
{
    return (int *)malloc(n * sizeof(int));
}

void citireV(int *v, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}
void afisV(int *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
}
int main()
{
    int n, *v;
    printf("n = ");
    scanf("%d", &n);
    v = alocV(v, n);
    printf("v = ");
    citireV(v, n);
    printf("\nv = ");
    afisV(v, n);
    free(v);
    return 0;
}