// sortare vector prin met selectiei
// in : v[] - initial
// out: v[] - sortat

#include <stdio.h>

void sortareV(int v[10], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

int main()
{
    int v[10], n;
    printf("n = ");
    scanf("%d", &n);
    printf("v = ");
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sortareV(v, n);
    printf("\nv = ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    return 0;
}