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
    int nr = 0;
    fread(&s, sizeof(Student), 1, f);
    while (!feof(f))
    {
        if (s.is == 1)
        {
            int sum = 0;
            for (int i = 0; i < 10; i++)
                sum += s.teme[i];
            if (sum == 10)
                printf("NAME: %s\n", s.nume);
        }
        fread(&s, sizeof(Student), 1, f);
    }

    fclose(f);
    return 0;
}