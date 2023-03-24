/*
CERINTA:
1. creeare fis
2. listare din fis binar in fisier text
3 operatie -> stergere + adaugare + conditie
4. listare in fis binar
5. exercitii

*/

#include <stdio.h>
typedef struct
{
    char denumire[20];
    float pret;
    int cant[12];
    char is;
} PRODUS;

int nrart(FILE *f, int l)
{
    long p;
    int n;
    p = ftell(f);
    fseek(f, 0, 2);
    n = ftell(f) / l;
    fseek(f, p, 0);
    return n;
}

int main()
{
    FILE *f;
    char nume[20];
    PRODUS p;
    int i, cod;

    printf("\nFisier: ");
    scanf("%s", &nume);
    f = fopen(nume, "wb+");
    // deschide pentru citire si scriere. daca fis exista, este suprascris, altfel este creat

    printf("\n Cod produs: ");
    scanf("%d", &cod);
    while (!feof(stdin))
    {
        if (cod >= nrart(f, sizeof(PRODUS)))
        {
            p.is = 0;
            fseek(f, 0, 2);
            for (i = nrart(f, sizeof(PRODUS)); i <= cod; i++)
                fwrite(&p, sizeof(PRODUS), 1, f);
        }
        fseek(f, cod * sizeof(PRODUS), 0);
        fread(&p, sizeof(PRODUS), 1, f);

        if (p.is)
            printf("\nExista deja un produs cu acest cod");
        else
        {
            fseek(f, cod * sizeof(PRODUS), 0);
            printf("Denumire: ");
            fflush(stdin);
            scanf("%s", &p.denumire);

            printf("pret:");
            scanf("%f", &p.pret);

            for (i = 0; i < 12; i++)
            {
                printf("Cant %d: ", i + 1);
                scanf("%d", &p.cant[i]);
            }

            p.is = 1;
            fwrite(&p, sizeof(PRODUS), 1, f);
        }

        printf("\nCod nou: ");
        scanf("%d", &cod);
    }
    fclose(f);
}
