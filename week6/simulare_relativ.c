#include <stdio.h>
#include <string.h>

typedef struct
{
    char is;
    int nr_matricol;
    char nume_prenume[25];
    int grupa;
    char an;
    struct
    {
        char c;
        char s;
    } Absente[15];
} Student;

void afis(const char *numeText)
{
    FILE *f = fopen("Fis_relativ_abs.dat", "rb");
    FILE *g = fopen(numeText, "w");
    Student s;

    if (f == NULL)
    {
        printf("Fis nu s-a deschis");
        return;
    }
    // print header for s
    fprintf(g, "Nr matricol \tNume \t\tGrupa \tAn \t\tAbsente\n");
    fread(&s, sizeof(Student), 1, f);
    int nr = 0;
    while (!feof(f))
    {
        if (s.nr_matricol > 0 && nr != s.nr_matricol)
        {
            fprintf(g, "%d \t\t\t%s \t\t%d \t%d \t\t", s.nr_matricol, s.nume_prenume, s.grupa, s.an);
            for (int i = 0; i < 15; i++)
            {
                fprintf(g, "%d ", s.Absente[i].c);
            }
            fprintf(g, "\n");
        }
        nr = s.nr_matricol;
        fread(&s, sizeof(Student), 1, f);
    }
    fclose(f);
    fclose(g);
}

int main()
{
    afis("output1.txt");
    Student s;
    int i, val, c, nr;
    FILE *f = fopen("Fis_relativ_abs.dat", "rb+");
    while (!feof(stdin))
    {
        printf("\nCare este numarul matricol al studentului ? ");
        scanf("%d", &nr);
        printf("\nCare este materia la care se schimba numarul de absente? ");
        scanf("%d", &i);
        printf("\nEste curs sau seminar? <0/1>? ");
        scanf("%d", &c);
        printf("Care este numarul de absente acum? ");
        scanf("%d", &val);
        fseek(f, sizeof(Student) * nr, 0);
        fread(&s, sizeof(Student), 1, f);
        if (c == 0)
        {
            s.Absente[i].c = val;
        }
        else
        {
            s.Absente[i].s = val;
        }
        fseek(f, sizeof(Student) * nr, 0);
        fwrite(&s, sizeof(Student), 1, f);
        fseek(f, 0, 1);
        printf("Care este noul cod de student? ");
        scanf("%d", &nr);
    }
    fclose(f);
    afis("output2.txt");
    return 0;
}