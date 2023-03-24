
// - de modificat denumirea la un produs pentru care codul se da de la tastatura;
// se va lista apoi in fișier text pentru verificare;
// - de modificat prețul prin reducerea acestuia cu 10 % pentru produsele care au vânzări mai mici de 40 pe tot anul.

#include <stdio.h>
#include <string.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cant[12];
    char is;
} Produs;

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
void listareBinToText(const char *numeBin, const char *numeText)
{
    FILE *f, *g;
    Produs p;
    int i, n = 0;
    f = fopen(numeBin, "rb");
    if (!f)
    {
        printf("FIS BINAR NU A FOST GASIT!");
        return;
    }
    g = fopen(numeText, "w");
    fprintf(g, "Nr. Denumire %12s Pret %5s Cantitati\n", "", "");
    fread(&p, sizeof(Produs), 1, f);
    while (!feof(f))
    {
        if (p.is)
        {
            fprintf(g, "%3d %-20s %.2f %5s", ++n, p.denumire, p.pret, "");
            for (i = 0; i < 12; i++)
                fprintf(g, "%3d ", p.cant[i]);
            fprintf(g, "\n");
        }
        fread(&p, sizeof(Produs), 1, f);
    }
    fclose(f);
    fclose(g);
}

int main()
{
    FILE *f;
    Produs p;
    listareBinToText("ProduseInitial.dat", "output1.txt");
    f = fopen("ProduseInitial.dat", "rb+");
    if (f == NULL)
    {
        printf("Can't open the file!");
        return 1;
    }
    int cod;
    printf("Enter the code: ");
    scanf("%d", &cod);
    if (cod > nrart(f, sizeof(Produs)))
    {
        printf("NU EXISTA IN ARTICOL. COD INVALID");
        fclose(f);
        return 1;
    }
    fseek(f, sizeof(Produs) * cod, 0);
    fread(&p, sizeof(Produs), 1, f);
    strcpy(p.denumire, "test");
    fseek(f, ftell(f) - sizeof(Produs), 0);
    fwrite(&p, sizeof(Produs), 1, f);
    fclose(f);
    listareBinToText("ProduseInitial.dat", "output2.txt");
    return 0;
}