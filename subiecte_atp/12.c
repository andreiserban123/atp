#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int nr_mat;
    char nume[30];
    int grupa;
    char probaPrac;
    char teme[10];
    char examen;

} Student;

void listareBinToText(const char *numeText)
{
    FILE *f = fopen("stud.dat", "rb");
    FILE *g = fopen(numeText, "w");
    if (!f || !g)
    {
        printf("EROARE LA DESCHIDEREA FISIERELOR!");
        return;
    }

    Student s;
    fprintf(g, "| %10s | %20s | %6s | %6s | %20s | %6s |\n", "Nr. matr.", "Nume", "Grupa", "Prob. Prac.", "Teme", "Examen");
    fprintf(g, "|------------|----------------------|--------|----------|----------------------|--------|\n");

    while (fread(&s, sizeof(Student), 1, f))
    {
        fprintf(g, "| %10d | %20s | %6d | %8d | ", s.nr_mat, s.nume, s.grupa, s.probaPrac);
        for (int i = 0; i < 10; i++)
        {
            fprintf(g, "%d ", s.teme[i]);
        }
        fprintf(g, "| %6d |\n", s.examen);
    }

    fclose(f);
    fclose(g);
}

int main()
{
    listareBinToText("Raport1.txt");
    FILE *f = fopen("stud.dat", "rb+");
    if (!f)
    {
        printf("Eroare la deschiderea fisierului!");
        return 1;
    }
    Student s;
    fread(&s, sizeof(Student), 1, f);
    float max = 0;
    while (!feof(f))
    {
        float nota = 10;
        nota += s.probaPrac;
        for (int i = 0; i < 10; i++)
        {
            nota += s.teme[i];
        }
        nota += s.examen;
        nota = (float)nota / 10;
        if (nota > max)
        {
            max = nota;
        }

        fread(&s, sizeof(Student), 1, f);
    }
    f = fopen("stud.dat", "rb");
    fread(&s, sizeof(Student), 1, f);
    while (!feof(f))
    {
        float nota = 10;
        nota += s.probaPrac;
        for (int i = 0; i < 10; i++)
        {
            nota += s.teme[i];
        }
        nota += s.examen;
        nota = (float)nota / 10;
        if (nota == max)
        {
            printf("Studentul cu nota maxima este: %s\n", s.nume);
        }

        fread(&s, sizeof(Student), 1, f);
    }
    fclose(f);
    return 0;
}