// Pb creeare fis bin org relativ vanz de prod pe 12 luni

#include <stdio.h>
#include <malloc.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cant[12];
    char is; // val de 0 sau 1
} PRODUS;

int nr_art(FILE *f, int l)
{
    long p;
    int n;
    p = ftell(f);     // retine poz curenta din fis
    fseek(f, 0, 2);   // poz la sf fis
    n = ftell(f) / l; // det nr art din fis
    fseek(f, p, 0);   // revenire la poz initiala
    return n;
}

int main()
{
    FILE *f;
    PRODUS p;
    int i, cod; // cod ajuta la poz art in fisier, confera unicitate art
    char nume[20];

    printf("NUME FISIER RELATIV:\n");
    gets_s(nume, 20);
    f = fopen(nume, "wb+"); // fopen_s(&f, nume, "wb+");
    if (f == NULL)
        return 1;
    printf("COD PRODUS:");
    scanf("%d", &cod);
    while (!feof(stdin))
    {
        if (cod >= nr_art(f, sizeof(PRODUS))) // op de preformare
        {
            p.is = 0;
            fseek(f, 0, 2);
            for (int i = nr_art(f, sizeof(PRODUS)); i < cod; i++)
            {
                fwrite(&p, sizeof(PRODUS), 1, f);
            }
        }
        fseek(f, cod * sizeof(PRODUS), 0); // poz la inceputul art
        fread(&p, sizeof(PRODUS), 1, f);
        if (p.is)
            printf("ARTICOLUL EXISTA DEJA");
        else
        {
            fseek(f, cod * sizeof(PRODUS), 0);
            printf("DENUMIRE: ");
            fflush(stdin);
            scanf("%s", &p.denumire);
            printf("PRET: ");
            scanf("%f", &p.pret);
            for (i = 0; i < 12; i++)
            {
                printf("cant[%d]", i + 1);
                scanf("%d", &p.cant[i]);
            }
            p.is = 1; // marcare art scris
            fwrite(&p, sizeof(PRODUS), 1, f);
        }
        printf("COD PRODUS NOU: \n");
        scanf("%d", &cod);
    }
    fclose(f);
    FILE *g;
    g = fopen("output.txt", "w");
    f = fopen(nume, "rb+");
    fprintf(g, "DENUMIRE\t PRET\t CANT\t\n");
    fread(&p, sizeof(PRODUS), 1, f);
    while (!feof(f))
    {
        if (p.is == 1)
        {
            fprintf(g, "%s\t %.2f\t", p.denumire, p.pret);
            for (int i = 0; i < 12; i++)
                fprintf(g, "%d ", p.cant[i]);
            fprintf(g, "\n");
        }
        fread(&p, sizeof(PRODUS), 1, f);
    }
    fclose(f);
    fclose(g);
    return 0;
}