// Fisierele sunt date volatile ale memoriei externe
// PROP FISIER
//-liniara, ordonata, omogena(prelucrare si semnficiate)
//-compus din articole (lungimi egale sau diferite)
// din punct de vedere fizic un fisier este compus din etichete: sir de
// octeti fara semnificatie intriseca
// reprezentare:text, binara
// inainte de citirea unei date alfanumerice, trebuie golit bufferul de intrare
// - gets_s
#include <stdio.h>
#include <malloc.h>

typedef struct
{
    char cnp[14];
    char nume[30];
    int an;
    int grupa;
    unsigned int nrd;
    unsigned int note[20];
} STUDENT;
int main()
{
    STUDENT x;

    return 0;
}