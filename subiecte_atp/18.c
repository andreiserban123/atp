#include <stdio.h>
typedef struct
{
    char is;
    int nrm;
    char nume[25];
    int grupa;
    char an;
    char absente[15][2];
} Student;

void afis(const char *nume)
{
    FILE *f, *g;
    f = fopen("Fis_relativ_abs.dat", "rb");
    g = fopen(nume, "w");
    if (g == NULL && f == NULL)
        return;
    Student s;
    fprintf(g, "%-4s%-15s%-8s%-6s%-4s", "Nr", "Nume", "Grupa", "An", "Absente");
    fprintf(g, "\n");
    fread(&s, sizeof(Student), 1, f);
    while (!feof(f))
    {
        if (s.is != 0)
        {
            fprintf(g, "%-4d%-10s%-8s%-6d%-2d%-8s", s.nrm, s.nume, " ", s.grupa, s.an, " ");
            for (int i = 0; i < 15; i++)
                fprintf(g, "%-4d%-4d", s.absente[i][0], s.absente[i][1]);
            fprintf(g, "\n");
        }
        fread(&s, sizeof(Student), 1, f);
    }
    fclose(f);
    fclose(g);
}

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
    afis("Raport1.txt");
    FILE *f = fopen("Fis_relativ_abs.dat", "rb+");
    if (f == NULL)
        return 0;
    Student s;

    printf("\nIntrodu numarul matricol al studentului: ");
    int nrm;
    scanf("%d", &nrm);
    int n = nrart(f, sizeof(Student));
    if (nrm >= n)
    {
        s.is = 0;
        fseek(f, 0, 2);
        for (int i = nrart(f, sizeof(Student)); i <= nrm; i++)
            fwrite(&s, sizeof(Student), 1, f);
    }
    fseek(f, nrm * sizeof(Student), 0);
    fread(&s, sizeof(Student), 1, f);
    if (s.is != 0)
    {
        printf("exista deja alt student cu acest numar matricol");
    }
    else
    {
        fseek(f, nrm * sizeof(Student), 0);
        s.nrm = nrm;
        printf("Introduceti numele studentului: ");
        scanf("%s", s.nume);
        printf("Introduceti grupa studentului: ");
        scanf("%d", &s.grupa);
        printf("Introduceti anul studentului: ");
        scanf("%d", &s.an);
        printf("absente:\n");
        for (int i = 0; i < 15; i++)
        {
            scanf("%d %d", &s.absente[i][0], &s.absente[i][1]);
        }
        s.is = 1;
        fwrite(&s, sizeof(Student), 1, f);
    }
    fclose(f);
    afis("Raport2.txt");
    return 0;
}