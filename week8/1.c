// det nr de elem neg din vector, cu elem reale
// a)met desc
// b)met reducerii

#include <stdio.h>

int nrneg1(float x[], int ls, int ld)
{
    int rez;
    if (ls == ld)
    {
        if (x[ls] < 0)
        {
            rez = 1;
        }
        else
            rez = 0;
    }
    else
    {
        rez = nrneg1(x, ls, (ls + ld) / 2) + nrneg1(x, ((ls + ld) / 2) + 1, ld);
    }

    return rez;
}

// med reducerii cu functie recursive

int nrneg2(float x[], int n)
{
    int rez;
    if (n == 0)
        rez = 0;
    else
    {
        rez = nrneg2(x, n - 1);
        if (x[n - 1] < 0)
            rez++;
    }
    return rez;
}

int main()
{
    int n;
    float x[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    // met descomp
    printf("Nr negative cu met descompunerii: %d\n", nrneg1(x, 0, n - 1));
    // met reducerii
    printf("Nr negative cu met reducerii: %d", nrneg2(x, n));

    return 0;
}