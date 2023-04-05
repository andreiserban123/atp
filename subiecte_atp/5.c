#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int nr_mat;
    char nume[30];
    char an;
    int grupa;
    char tip;
    struct
    {
        char zi;
        char luna;
        int an;
    } Data;

    struct
    {
        char ora;
        char minut;
    } oraInt;
    struct
    {
        char ora;
        char minut;
    } oraIesire;

} Student;
void listareBinToText(const char *numeBin, const char *numeText)
{
    FILE *f, *g;
    Student s;
    int i, n = 0;
    f = fopen(numeBin, "rb");
    if (!f)
    {
        printf("FIS BINAR NU A FOST GASIT!");
        return;
    }
    g = fopen(numeText, "w");
    fread(&s, sizeof(Student), 1, f);
    fprintf(g, "  Nr. matr.  |   Nume   | An | Grupa | Tip | Data        | Ora intrare | Ora iesire |\n");
    fprintf(g, "-----------------------------------------------------------------------------\n");

    while (!feof(f))
    {
        // print the struct
        fprintf(g, "  %10d | %8s | %2d | %5d |  %c  | %02d/%02d/%4d |     %02d:%02d    |   %02d:%02d   |\n",
                s.nr_mat, s.nume, s.an, s.grupa, s.tip, s.Data.zi, s.Data.luna, s.Data.an, s.oraInt.ora, s.oraInt.minut, s.oraIesire.ora, s.oraIesire.minut);
        fread(&s, sizeof(Student), 1, f);
    }
    fclose(f);
    fclose(g);
}
int cmpStudent(const void *a, const void *b)
{
    return strcmp(((Student *)a)->nume, ((Student *)b)->nume);
}
void sortareBinar(const char *numeBin)
{
    FILE *f;
    Student s;
    int n = 0, i;
    f = fopen(numeBin, "rb+");
    if (!f)
    {
        printf("FISIERUL NU A FOST GASIT!");
        return;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f) / sizeof(Student);
    rewind(f);
    Student *studenti = (Student *)malloc(n * sizeof(Student));
    fread(studenti, sizeof(Student), n, f);
    qsort(studenti, n, sizeof(Student), cmpStudent);
    rewind(f);
    fwrite(studenti, sizeof(Student), n, f);
    fclose(f);
    free(studenti);
}
int main()
{
    listareBinToText("SecvStud.dat", "Raport1.txt");
    sortareBinar("SecvStud.dat");
    listareBinToText("SecvStud.dat", "Raport2.txt");
    return 0;
}