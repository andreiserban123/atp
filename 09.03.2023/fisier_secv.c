// Creeare fisier creat secvential
// input: date de la tast
#include <stdio.h>

typedef struct
{
    int nr;        // nr matricol
    char nume[30]; // nume
    int an;        // anul de studiu
    int grupa;     // grupa
    int n;         // nr de discipline
    int note[15];  // notele

} STUDENT;

int main()
{
    FILE *f;
    STUDENT s;
    int i;
    char s1[30];
    printf("Nume fisier binar: ");
    gets(s1);
    f = fopen(s1, "wb"); // f = fopen("stud.dat", "wb");
    if (f == NULL)
    {
        printf("NU SE POATE DESCHIDE FISIERUL");
        return 1;
    }
    printf("Nr matricol: ");
    scanf("%d", &s.nr);
    while (!feof(stdin))
    {
        printf("Nume: ");
        fflush(stdin);
        scanf("%s", s.nume);
        printf("An: ");
        scanf("%d", &s.an);
        printf("Grupa: ");
        scanf("%d", &s.grupa);
        printf("Nr discipline: ");
        scanf("%d", &s.n);
        for (i = 0; i < s.n; i++)
        {
            printf("Nota %d: ", i + 1);
            scanf("%d", &s.note[i]);
        }
        fwrite(&s, sizeof(STUDENT), 1, f);
        printf("Nr matricol: ");
        scanf("%d", &s.nr);
    }
    fclose(f);
    f = fopen(s1, "rb");
    FILE *g;
    g = fopen("stud.txt", "wt");
    if (g == NULL)
    {
        printf("NU SE POATE DESCHIDE FISIERUL");
        return 1;
    }
    fread(&s, sizeof(STUDENT), 1, f);
    while (!feof(f))
    {
        fprintf(g, "Nr matricol: %d", s.nr);
        fprintf(g, " Nume: %s", s.nume);
        fprintf(g, " An: %d", s.an);
        fprintf(g, " Grupa: %d", s.grupa);
        fprintf(g, " Nr discipline: %d", s.n);
        fprintf(g, " Note: ");
        for (i = 0; i < s.n; i++)
            fprintf(g, "Nota %d %d: ", i + 1, s.note[i]);
        fprintf(g, "\n");
        fread(&s, sizeof(STUDENT), 1, f);
    }
    fclose(f);
    fclose(g);
    return 0;
}