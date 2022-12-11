#include <stdio.h>
#include "functions.c"

int main()
{
    FILE* in = NULL;
    FILE* out = NULL;
    
    printf("Enter an input file name wihout extension.\n");
    fileValidation(in, "r");

    printf("Enter an input file name wihout extension.\n");
    fileValidation(in, "w");

    menu();

    fclose(in);
    fclose(out);

    return 0;
}