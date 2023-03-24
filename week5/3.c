// modifca fisierul binar daca au
#include <stdio.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cant[12];
    char is;
} Produs;

int main()
{
    FILE *f;
    Produs p;
    f = fopen("ProduseInitial.dat", "rb+");
    int i, e, n = 0;
    if (!f)
        return 1;
    fread(&p, sizeof(Produs), 1, f);
    while (!feof(f))
    {
        if (p.is)
        {
            e = 0;
            for (i = 0; i < 12 && e < 3; i++)
            {
                if (p.cant[i] == 0)
                    e++;
            }
            if (e >= 3)
            {
                printf("\n %-20s", p.denumire);
                fseek(f, ftell(f) - sizeof(Produs), SEEK_SET);
                p.is = 0;
                fwrite(&p, sizeof(Produs), 1, f);
                fseek(f, 0, 1); // nevoie pentru a revenii la functia de citire
                n++;
            }
        }
        fread(&p, sizeof(Produs), 1, f);
    }
    fclose(f);
    printf("Au fost sterse %d articole", n);
    return 0;
}