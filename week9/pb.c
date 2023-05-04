#include <stdio.h>

void sumaPar(int n, int v[], int sol[], int *k)
{
    // sort desc
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (v[i] < v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 0 && v[i] > 0)
            sol[(*k)++] = v[i];
}

int main()
{
    int n, v[100], sol[100], k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", v + i);
    sumaPar(n, v, sol, &k);
    for (int i = 0; i < k; i++)
        printf("%d ", sol[i]);
    return 0;
}