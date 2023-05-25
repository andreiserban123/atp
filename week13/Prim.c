#include <stdio.h>
#include <malloc.h>

// preia datele unui graf in forma tabelara din fisierul nume si obtine
// matricea ponderilor, unde MAX este valoarea cu seminificatie de infinit
// ultima linie a fisierului contine varful initial din algoritmul Prim

void preia_graf(const char *nume, float ***w, int *n, int *v0, float MAX)
{
    FILE *f = fopen(nume, "rt");

    fscanf(f, "%i", n);
    int i, j, m;

    float **mw = (float **)malloc(*n * sizeof(float *));
    for (i = 0; i < *n; i++)
        mw[i] = (float *)malloc(*n * sizeof(float));

    fscanf(f, "%i", &m);

    for (i = 0; i < *n; i++)
        for (j = 0; j < *n; j++)
            mw[i][j] = MAX;
    for (i = 0; i < m; i++)
    {
        int u, v;
        float p;
        fscanf(f, "%i", &u);
        fscanf(f, "%i", &v);
        fscanf(f, "%f", &p);
        mw[u - 1][v - 1] = mw[v - 1][u - 1] = p;
    }
    fscanf(f, "%i", v0);
    fclose(f);
    *w = mw;
}

// implementarea algoritmului lui Prim
float Prim(float **w, int n, int v0, int ***arb, float MAX)
{
    float cost = 0;
    int *ind = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
        ind[i] = 0;
    ind[v0 - 1] = 1;
    // ind este vectorul indicator: ind[i]=1, daca varful i+1 a fost trecut in A, altfel este 0
    int **muchii = (int **)malloc((n - 1) * sizeof(int *));
    for (i = 0; i < n - 1; i++)
        muchii[i] = (int *)malloc(2 * sizeof(int));
    for (i = 0; i < n - 1; i++)
    {
        int u, v, vf1, vf2;
        float cmin = MAX;
        for (u = 1; u <= n; u++)
            if (ind[u - 1])
                for (v = 1; v <= n; v++)
                    if ((!ind[v - 1]) && (w[u - 1][v - 1] <= cmin))
                    {
                        vf1 = u;
                        vf2 = v;
                        cmin = w[u - 1][v - 1];
                    }
        cost += cmin;
        muchii[i][0] = vf1;
        muchii[i][1] = vf2;
        ind[vf2 - 1] = 1;
    }
    *arb = muchii;
    free(ind);
    return cost;
}

int main()
{
    float **w, cost, MAX;
    MAX = 1000000;
    int n, v0, **muchii;
    preia_graf("graf.txt", &w, &n, &v0, MAX);
    cost = Prim(w, n, v0, &muchii, MAX);
    printf("Arborele de cost minim cu v0=%i\n", v0);
    int i;
    for (i = 0; i < n - 1; i++)
        printf("(%i,%i) ", muchii[i][0], muchii[i][1]);
    printf("\nCostul:%8.2f", cost);
    for (i = 0; i < n; i++)
        free(w[i]);
    free(w);
    for (i = 0; i < n - 1; i++)
        free(muchii[i]);
    free(muchii);
}
