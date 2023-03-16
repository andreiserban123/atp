// lucru cu fisiere text si binare
// fiser binar ".dat"
// fwrite fread pentru fisier binar
// fiser text ".txt"
// fprintf fscanf

#include <stdio.h>

int main()
{
    FILE *f, *g;
    float x[5] = {1, 2, 3, 4, 5};
    float y;
    f = fopen("FisBin.dat", "wb");
    fwrite(x, sizeof(x[0]), sizeof(x) / sizeof(x[0]), f);
    fclose(f);
    f = fopen("FisBin.dat", "rb");
    g = fopen("FisText.txt", "w");
    if (!f) // f == NULL
        printf("Fisierul binar nu s-a putut deschide");
    else if (!g)
        printf("Fisierul text nu s-a deschis");
    else
    {
        float y;
        fread(&y, sizeof(float), 1, f);
        while (!feof(f))
        {
            fprintf(g, "%.2f ", y);
            fread(&y, sizeof(float), 1, f);
        }
    }
    fclose(f);
    fclose(g);
    return 0;
}
