#include <stdio.h>
#include <malloc.h>
// Verifica daca valoarea elementului i este acceptabila
int posibil(int *v, int i)
{
    int j;
    for (j = 0; j < i; j++)
        if (v[i] == v[j])
            return 0;
    return 1;
}
// Afisare solutie pe ecran
// I: numarul solutiei (num), dimensiunea permutarii (nr), permutarea (v)
void retine_solutia(int num, int nr, int *v)
{
    int i;
    printf("\nSolutia nr.%d: ", num);
    for (i = 0; i < nr; i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Genereaza permutari de n elemente (1..n)
// I: n
// E: numar permutari
int permutari(int n)
{

    int *v = (int *)malloc(n * sizeof(int));
    int i, j, nr = 0;
    for (i = 0; i < n; i++)
        v[i] = 0;
    i = 0;
    while (i >= 0)
    {
        j = 0;
        while (j < n && !posibil(v, i))
        {
            v[i]++;
            j++;
        }
        if (j < n)
        {
            if (i == n - 1)
            {
                nr++;
                retine_solutia(nr, n, v);
            }
            else
                i++;
        }
        else
            i--;
    }
    free(v);
    return nr;
}
// Permutari recursiv
// I: dimensiune (n), pas curent (i), sol. partiala curenta (x),  nr. crt. sol. (nr)
// E: numar solutii (nr)
int permutari_r(int n, int i, int *x, int nr)
{
    int j;
    if (i == n)
        retine_solutia(++nr, n, x);
    else
        for (j = 1; j <= n; j++)
        {
            x[i] = j;
            if (posibil(x, i))
                nr = permutari_r(n, i + 1, x, nr);
        }
    return nr;
}

int main()
{
    int n, nr;
    printf("n=");
    scanf("%d", &n);
    int *x = (int *)malloc(n * sizeof(int));
    nr = 0;
    nr = permutari_r(n, 0, x, 0); // apel pentru varianta recursiva
    printf("\nNumar solutii: %d\n", nr);
    free(x);
    return 0;
}
