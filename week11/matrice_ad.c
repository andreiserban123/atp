#include <stdio.h>

// Preluare graf din fis text in forma tabelara si apoi conversie in forma matriciala, respectiv
// matrice de adiacenta
// IN : nume fisier
// OUT: nr de vf -nrv, nr de muchii  -nrm , forma tabelar a grafului - g[][2]

int preluareGraf(const char *nume, int *nrv, int *nrm, int g[][2])
{
    int er, i;
    FILE *f;
    f = fopen(nume, "r");
    if (!f)
        er = 1; // fis text nu s a deschis
    else
    {
        er = 0;                               // fis text s a deschis
        fscanf(f, "%d %d", &(*nrv), &(*nrm)); // pot sa raman decat cu nrv, nrm deoarece * si & se anuleaza
        printf("%d %d\n\n", *nrv, *nrm);
        for (int i = 0; i < *nrm; i++)
        {
            fscanf(f, "%d %d", &g[i][0], &g[i][1]);
            printf("%d %d \n", g[i][0], g[i][1]);
        }
    }
    fclose(f);
    return er;
}

// fct preluare graf din fis text si copiere in forma tabelara
// IN : nr de vf - nrv, nr de muchii - nrm, forma tabelara a grafului - tabel[][2]
// OUT : mat de adiacenta - mat[6][6], dimensiunea mat - dim

void conversieTableToMatrice(int nrv, int nrm, int tabel[][2], int mat[6][6], int *dim)
{
    int i, j;
    *dim = nrv;
    // initializare cu 0 a mat de adiacenta
    for (i = 0; i < *dim; i++)
    {
        for (j = 0; j < *dim; j++)
        {
            mat[i][j] = 0;
        }
    }
    for (i = 0; i < nrm; i++)
    {
        mat[tabel[i][0] - 1][tabel[i][1] - 1] = 1;
        mat[tabel[i][1] - 1][tabel[i][0] - 1] = 1;
    }
}

// functia de conversie din forma tabelara in forma matriciala (mat de adiacenta)

// func pentru afisare mat
void afisMat(int mat[][6], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int nrv, nrm, mat[6][6], tabel[8][2], er, dim;
    // mat[][] matricea de adicaenta
    // tabel forma tabelara
    // dim matricei
    er = preluareGraf("g1.txt", &nrv, &nrm, tabel);
    if (er == 1)
    {
        printf("Fisierul nu s a deschis");
    }
    else
    {
        printf("fisierul s a deschis");
    }
    conversieTableToMatrice(nrv, nrm, tabel, mat, &dim);
    afisMat(mat, nrv);
    return 0;
}