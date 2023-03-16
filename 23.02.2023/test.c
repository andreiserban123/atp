// read input from file
// write output to file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
    FILE *ptr, *ptr1;
    char ch;

    // Opening file in reading mode
    ptr = fopen("test.txt", "r");
    ptr1 = fopen("test.txt", "w");
    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }
    // write in test.txt
    fprintf(ptr1, "Hello World!");

    // Closing the file
    fclose(ptr);
    return 0;
}