// suma elem unui vector cu elem intregi cu nr impare cu met reducerii recursiv
#include <stdio.h>

int nrelemimp(int x[], int n)
{
    int rez;
    if (n == 0)
        rez = 0;
    else
    {
        rez = nrelemimp(x, n - 1);
        if (x[n - 1] % 2 == 1)
            rez += x[n - 1];
    }
    return rez;
}

int main()
{
    int n, x[10];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    printf("Suma elem impare este: %d", nrelemimp(x, n));
}