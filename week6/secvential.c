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
    Student student;
    int i, n = 0;
    f = fopen(numeBin, "rb");
    if (!f)
    {
        printf("FIS BINAR NU A FOST GASIT!");
        return;
    }
    g = fopen(numeText, "w");
    // fprintf(g, "\nNr. matricol %5s Nume %5s ", "");
    fread(&student, sizeof(Student), 1, f);
    while (!feof(f))
    {
        // print the student struct
        fprintf(g, "Nr. matricol: %d\n", student.nr_mat);
        fprintf(g, "Nume: %s\n", student.nume);
        fprintf(g, "An: %d\n", student.an);
        fprintf(g, "Grupa: %d\n", student.grupa);
        fprintf(g, "Tip: %c\n", student.tip);
        fprintf(g, "Data: %d/%d/%d\n", student.Data.zi, student.Data.luna, student.Data.an);
        fprintf(g, "Ora intrare: %d:%d\n", student.oraInt.ora, student.oraInt.minut);
        fprintf(g, "Ora iesire: %d:%d\n", student.oraIesire.ora, student.oraIesire.minut);
        fprintf(g, "\n");
        fread(&student, sizeof(Student), 1, f);
    }
    fclose(f);
    fclose(g);
}
int main()
{
    listareBinToText("SecvStud.dat", "Raport1.txt");
    FILE *f = fopen("SecvStud.dat", "rb+");
    if (!f)
    {
        printf("FISIERUL NU A FOST GASIT!");
        return 0;
    }
    Student student;
    fseek(f, 0, SEEK_END);
    printf("\nNr. matricol:");
    scanf("%d", &student.nr_mat);
    printf("\nNume: ");
    scanf("%s", &student.nume);
    printf("\nAn: ");
    scanf("%d", &student.an);
    printf("\nGrupa: ");
    scanf("%d", &student.grupa);
    printf("\nTip: ");
    scanf(" %c", &student.tip);
    printf("\nData: ");
    scanf("%d %d %d", &student.Data.zi, &student.Data.luna, &student.Data.an);
    printf("\nOra intrare: ");
    scanf("%d %d", &student.oraInt.ora, &student.oraInt.minut);
    fwrite(&student, sizeof(Student), 1, f);
    fclose(f);
    listareBinToText("SecvStud.dat", "Raport2.txt");
    return 0;
}