// https : // infocadsite.wordpress.com/2017/02/14/metoda-bisectiei/
// MET BISECTIEI
#include <stdio.h>
#include <math.h>

float fct(float x)
{
    return x * x * x - 3 * x + 14; // pas 1
}

void bisectiei(float a, float b, float (*f)(float), float eps, long n, int *cod, float *x)
{
    // cod = 0 daca nu s a gasit
    long c;
    int gata = 0;
    for (c = 0; c <= n && !gata; c++)
    {
        *x = (a + b) / 2;
        gata = fabs(*x - a) < eps;
        if ((*f)(*x) * (*f)(a) < 0)
            b = *x;
        else
            a = *x;
    }
    *cod = gata;
}

int main()
{
    float a, b, eps, x;
    long n;
    int cod;
    float (*functie)(float); // pas 2
    printf("Dati limitele intervalului [a,b]:\n");
    scanf("%f %f", &a, &b);
    printf("Dati eroarea maxim admisibila:\n");
    scanf("%f", &eps);
    printf("Dati nr maxim de iteratii:\n");
    scanf("%li", &n);
    functie = fct;                              // pas 3
    bisectiei(a, b, functie, eps, n, &cod, &x); // apelarea unei functii prin intermediul unui parametru
    if (!cod)                                   // cod == 0
        printf("NU EXISTA SOLUTII");
    else // cod == 1
        printf("Solutia este: %.2f", x);
    return 0;
}

// Dati limitele intervalului [a,b]:
// -10 10
// Dati eroarea maxim admisibila:
// 0.01
// Dati nr maxim de iteratii:
// 1000
// Solutia este: -2.82