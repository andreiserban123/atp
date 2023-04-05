#include <stdio.h>
#include <string.h>

typedef struct
{
    int nr_mat;
    char nume[30];
    int grupa;
    char probaPractica;
    char teme[10];
    char examen;
    char is;
} Student;

int nr_art(FILE *f, int l)
{
    long p = ftell(f);
    fseek(f, 0, SEEK_END);
    int n = ftell(f) / l;
    fseek(f, p, SEEK_SET);
    return n;
}
void afis(const char *name)
{
    FILE *f = fopen("atp.dat", "rb");
    FILE *g = fopen(name, "w");

    fprintf(g, "%-4s%-20s%-8s%-20s%-8s%-40s\n", "Nr", "Nume", "Grupa", "Proba practica", "Examen", "Teme");

    Student s;
    fread(&s, sizeof(Student), 1, f);

    while (!feof(f))
    {
        if (s.is == 1)
        {
            fprintf(g, "%-4d%-20s%-8d%-20d%-8d", s.nr_mat, s.nume, s.grupa, s.probaPractica, s.examen);

            for (int i = 0; i < 10; i++)
                fprintf(g, "%-4d", s.teme[i]);

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
    Student s;
    FILE *f = fopen("atp.dat", "rb+");
    printf("Introduceti nr matricol: ");
    int nrm;
    scanf("%d", &nrm);
    if (nrm >= nr_art(f, sizeof(Student)))
    {
        s.is = 0;
        fseek(f, 0, 2);
        for (int i = nr_art(f, sizeof(Student)); i <= nrm; i++)
            ;
        fwrite(&s, sizeof(Student), 1, f);
    }
    fseek(f, nrm * sizeof(Student), SEEK_SET);
    fread(&s, sizeof(Student), 1, f);
    if (s.is != 0)
    {
        printf("Student existent deja");
    }
    else
    {
        fseek(f, nrm * sizeof(Student), SEEK_SET);
        s.nr_mat = nrm;
        printf("Introduceti numele: ");
        scanf("%s", s.nume);
        printf("Introduceti grupa: ");
        scanf("%d", &s.grupa);
        printf("Introduceti nota proba practica: ");
        scanf("%d", &s.probaPractica);
        printf("Introduceti temele: \n");
        for (int i = 0; i < 10; i++)
            scanf("%d", &s.teme[i]);
        printf("Introduceti nota examen: ");
        scanf("%d", &s.examen);
        s.is = 1;
        fwrite(&s, sizeof(Student), 1, f);
        fseek(f, 0, 1);
    }
    fclose(f);
    afis("Raport2.txt");
    return 0;
}