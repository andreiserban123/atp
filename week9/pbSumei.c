#include <stdio.h>
#include <stdlib.h>

void plataSuma(int suma, int t[], int n, int sol[])
{
    int i, sr = suma;
    for (i = 0; i < n; i++)
    {
        sol[i] = sr / t[i];
        sr = sr % t[i];
    }
}

int main()
{
    // 4 3 1 5
    int suma, n, b[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", b + i);
    }
    // sort desc
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (b[i] < b[j])
            {
                int aux = b[i];
                b[i] = b[j];
                b[j] = aux;
            }
    scanf("%d", &suma);
    int sol[10];
    plataSuma(suma, b, n, sol);
    for (int i = 0; i < n; i++)
        printf("%d ", sol[i]);

    return 0;
}