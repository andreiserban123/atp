#include <stdio.h>
#define freadb(x, f) fread(&(x), sizeof(x), 1, (f))
#define fwriteb(x, f) fwrite(&(x), sizeof(x), 1, (f))

typedef struct
{
    int nr;        // nr matricol
    char nume[30]; // nume
    int an;        // anul de studiu
    int grupa;     // grupa
    int n;         // nr de discipline
    int note[15];  // notele

} STUDENT;

int main()
{
    FILE *f, *g;
    STUDENT s;
    int i, n;
    char s1[20];
    printf("NUME FISIER BINAR: ");
    gets(s1);
    f = fopen(s1, "rb");
    if (f == NULL)
    {
        printf("NU SE POATE DESCHIDE FISIERUL");
        return 1;
    }
    printf("NUME FISIER TEXT: ");
    gets(s1);
    g = fopen(s1, "wt");
    if (g == NULL)
    {
        printf("NU SE POATE DESCHIDE FISIERUL TEXT");
        return 1;
    }
    fprintf(g, "\n Nr  %25sNume An  Grupa  NrDiscipline  Notele", "");
    n = 0;
    freadb(s, f);
    while (!feof(f))
    {
        fprintf(g, "\n%3d %25s %2d %4d", ++n, s.nume, s.an, s.grupa, s.n);
        for (i = 0; i < s.n; i++)
            fprintf(g, "%2d ", s.note[i]);
        freadb(s, f);
    }
    fclose(f);
    fclose(g);
    return 0;
}