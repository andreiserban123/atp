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

int main()
{
    afis("Raport1.txt");
    FILE *f = fopen("Fis_relativ_abs.dat", "rb+");
    if (f == NULL)
        return 0;
    Student s;
    fread(&s, sizeof(Student), 1, f);
    int maxim = 0;
    while (!feof(f))
    {
        if (s.absente[0][1] > maxim)
            maxim = s.absente[0][1];
        fread(&s, sizeof(Student), 1, f);
    }
    fclose(f);
    f = fopen("Fis_relativ_abs.dat", "rb+");
    fread(&s, sizeof(Student), 1, f);
    printf("Studentii cu cele mai multe absente sunt:");
    while (!feof(f))
    {
        if (s.absente[0][1] == maxim && s.is == 1)
        {
            printf(" %s ", s.nume);
        }
        fread(&s, sizeof(Student), 1, f);
    }
    // afis("Raport2.txt");
    return 0;
}