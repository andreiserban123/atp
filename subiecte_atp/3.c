#include <stdio.h>
#include <string.h>

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
int main()
{
    listareBinToText("SecvStud.dat", "Raport1.txt");
    FILE *f = fopen("SecvStud.dat", "rb+");
    if (f == NULL)
    {
        printf("FISIERUL NU A FOST GASIT!");
        return 0;
    }
    Student student;
    fread(&student, sizeof(Student), 1, f);
    while (!feof(f))
    {
        if (student.nr_mat == 6903)
        {
            int minS, minF;
            minS = student.oraInt.minut + student.oraInt.ora * 60;
            minF = student.oraIesire.minut + student.oraIesire.ora * 60;
            int h = (minF - minS) / 60;
            int min = (minF - minS) % 60;
            printf("A stat : %d ore si  %d minute", h, min);
        }
        fread(&student, sizeof(Student), 1, f);
    }
    return 0;
}