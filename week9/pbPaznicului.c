#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int paznic(int x, int y, int m, int n)
{
    int nr = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            nr += (cmmdc((abs(x - i)), (abs(y - j))) == 1);
        }
    return nr;
}

int main()
{
    int x = 1, y = 1, m = 3, n = 5;
    printf("%d", paznic(x, y, m, n));

    return 0;
}