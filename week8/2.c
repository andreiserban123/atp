// sa se det produsul scalar a doi vectori de n elemente, cu n citit de la tastatura

#include <stdio.h>

// a) met descompunerii

float ps1(float x[], float y[], int ls, int ld)
{
    float s;
    if (ls == ld)
    {
        s = x[ls] * y[ls];
    }
    else
    {
        s = ps1(x, y, ls, (ls + ld) / 2) + ps1(x, y, ((ls + ld) / 2) + 1, ld);
    }

    return s;
}

// b) met reducerii recursiv
float ps2(float x[], float y[], int n)
{
    float p;
    if (n == 0)
    {
        p = 0;
    }
    else
    {
        p = ps2(x, y, n - 1) + x[n - 1] * y[n - 1];
    }

    return p;
}

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);

    float x[n], y[n];

    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Met descompunerii
    printf("\nprodusul scalar este: %.2f", ps1(x, y, 0, n - 1));
    // Met reducerii recursiv
    printf("\nprodusul scalar este: %.2f", ps2(x, y, n));
    return 0;
}