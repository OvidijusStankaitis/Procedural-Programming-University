#include <stdio.h>

#define fileLength 256

FILE* fileValidation(FILE* file, char fileName[])
{
    scanf("%s", fileName);
    file = fopen(fileName, "r");

    while(file == NULL)
    {
        printf("File not found. Please enter an input file name with extension:\n");
        scanf("%s", fileName);

        file = fopen(fileName, "r");
    }

    return file;
}

int main()
{
    FILE* input = NULL;
    FILE* output = NULL;

    char fileName[fileLength];
    char random[10];
    
    printf("Please enter an input file name with extension:\n");

    input = fileValidation(input, fileName);

    return 0;
}