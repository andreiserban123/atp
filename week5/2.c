#include <stdio.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cant[12];
    char is;
} Produs;

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
    fprintf(g, "\nNr. Denumire %5s Pret Cantitati", "");
    fread(&p, sizeof(Produs), 1, f);
    while (!feof(f))
    {
        if (p.is)
        {
            fprintf(g, "\n%3d %-20s %6.2f", ++n, p.denumire, p.pret);
            for (i = 0; i < 12; i++)
                fprintf(g, "%3d ", p.cant[i]);
        }
        fread(&p, sizeof(Produs), 1, f);
    }
    fclose(f);
    fclose(g);
}

int main()
{
    listareBinToText("ProduseInitial.dat", "Raport1.txt");
    return 0;
}