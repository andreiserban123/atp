#include <stdio.h>

typedef struct
{

    char is;
    int marca;
    char nume[30];
    int an;
    int grupa;
    unsigned int nrd;
    unsigned int note[20];

} STUDENT;

void preformare_ext(FILE *f, int p, int nra)
{
    STUDENT x;
    x.is = 0;
    int i;
    fseek(f, 0, SEEK_SET);
    for (i = 0; i < nra; i++)
    {
        fwrite(&x, sizeof(x), 1, f);
    }
}
int nr_articole(FILE *f)
{
    long poz_c = ftell(f);
    fseek(f, 0, SEEK_END);
    int n = ftell(f) / sizeof(STUDENT);
    fseek(f, poz_c, SEEK_SET);
    return n;
}

void prelucreaza(char nume_fis[30], int nrgr)
{
    FILE *f, *lista;
    STUDENT x;
    char *nume_fisO;
    char nume2[7];
    char nume1[30] = "Grupa";
    _itoa(nrgr, nume2, 10);
    nume_fisO = strcat(nume1, nume2);
    fopen_s(&lista, nume_fisO, "w");
    fopen_s(&f, nume_fis, "rb");
    fread(&x, sizeof(x), 1, f);
    int gasit = 0;
    while (!feof(f))
    {
        if (x.grupa == nrgr)
        {
            if (!gasit)
            {
                fprintf(lista, "%s%d%s", "Grupa ", nrgr, ":\n");
                gasit = 1;
            }
            fprintf(lista, "%s%s", x.nume, "\n");
        }
        fread(&x, sizeof(x), 1, f);
    }
    fclose(f);
    fclose(lista);
    if (!gasit)
    {
        remove(nume_fisO);
    }
}
void consulatare_selectie(char nume_fis[30])
{
    int nrgr;
    printf("%s", nume_fis);
    scanf("%d", &nrgr);
    while (!feof(stdin))
    {
        prelucreaza(nume_fis, nrgr);
        printf("GRUPA SAU CTRL+Z PENTRU IESIRE:\n");
        scanf("%d", &nrgr);
    }
}

void creare_adugare_pop(char nume[30], int nra_preformare, int opt)
{
    STUDENT x;
    FILE *f;
    int i, n;
    int mc;
    char temp[3];
    if (opt == 1)
    {
        f = fopen(nume, "wb+");
        preformare_ext(f, 0, nra_preformare - 1);
    }
    else
        f = fopen(nume, "rb+");
    printf("MARCA SAU CTRL+Z PENTRU IESIRE:\n");
    scanf("%d", &mc);
    while (!feof(stdin))
    {
        n = nr_articole;
        if (n < mc)
            preformare_ext(f, n, mc);
        fseek(f, mc * sizeof(STUDENT), SEEK_SET);
        fread(&x, sizeof(x), 1, f);
        if (x.is = 1)
            printf("ARTICOL EXISTENT\n");
        else
        {
            x.marca = mc;
            x.is = 1;
            printf("NUME:\n");
            gets(temp);
            gets(x.nume);
            printf("AN:\n");
            scanf("%d", &x.an);
            printf("GRUPA:\n");
            scanf("%d", &x.grupa);
            printf("NR discipline:\n");
            scanf("%d", &x.nrd);
            for (i = 0; i < x.nrd; i++)
            {
                printf("Nota %d:\n", i + 1);
                scanf("%d", &x.note[i]);
            }
            fseek(f, mc * sizeof(STUDENT), SEEK_SET);
            fwrite(&x, sizeof(x), 1, f);
        }
        printf("MARCA SAU CTRL+Z PENTRU IESIRE:\n");
        scanf("%d", &mc);
    }
    fclose(f);
}

int main()
{
}