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
    Student s;
    FILE *f = fopen("SecvStud.dat", "rb+");
    if (!f)
    {
        printf("FISIERUL NU A FOST GASIT!");
        return 0;
    }
    printf("Introdu numarul matricol al studentului: ");
    scanf("%d", &s.nr_mat);
    printf("Introdu numele studentului: ");
    scanf("%s", s.nume);
    printf("Introdu anul studentului: ");
    scanf("%d", &s.an);
    printf("Introdu grupa studentului: ");
    scanf("%d", &s.grupa);
    printf("Introdu tipul: ");
    scanf(" %c", &s.tip);
    printf("Introdu data: ");
    scanf("%d/%d/%d", &s.Data.zi, &s.Data.luna, &s.Data.an);
    printf("Introdu ora de intrare a studentului: ");
    scanf("%d:%d", &s.oraInt.ora, &s.oraInt.minut);
    s.oraIesire.ora = 0;
    s.oraIesire.minut = 0;
    fseek(f, 0, SEEK_END);
    fwrite(&s, sizeof(Student), 1, f);
    fclose(f);
    listareBinToText("SecvStud.dat", "Raport2.txt");
    return 0;
}