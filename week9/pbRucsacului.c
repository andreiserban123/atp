// forma intreaga

// IN : q-capacitatea rucsacului, n-numar obiecte, c[] - vector capacitati
// OUT: sol[] - vector solutie

#include <stdio.h>
#include <stdlib.h>

void rucsacIntr(float q, int n, float c[], int sol[])
{
    float qr; // capacitatea ramasa
    int i;
    qr = q;
    for (int i = 0; i < n; i++)
    {
        if (qr >= c[i]) // verificare daca obiectul incape in rucsac
        {
            sol[i] = 1; // adaugare obiect
            qr -= c[i]; // verificare capacitate ramasa
        }
        else
        {
            sol[i] = 0; // nu adaug obiect
        }
    }
}

int main()
{
    float CT = 33;                                 // capacitate totala
    float c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // vector capacitati
    float v[10] = {3, 2, 1, 4, 5, 3, 2, 7, 1, 8};  // vector valori
    int sol[10];                                   // vector solutie
    int i, j;
    float castig = 0; // castigul maxim
    float aux;
    int n = 10;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] / c[i] < v[j] / c[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
    rucsacIntr(CT, n, c, sol);

    for (int i = 0; i < n; i++)
    {
        printf("\n%2d c=%.2f v=%.2f, %2d, castig=%.2f", i + 1, c[i], v[i], sol[i], castig = castig + sol[i] * v[i]);
    }

    return 0;
}