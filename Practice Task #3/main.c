#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fileLength 256
#define fileNoExtLength 252
#define textLength 256

FILE* fileValidation(FILE* file);
void inputRead(char*** text, FILE* input, int* size);

int main()
{
    FILE* input = NULL;

    input = fileValidation(input);

    char** text;

    int size;

    inputRead(&text, input, &size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\n", strlen(text[i]));
    }

    free(text);
    return 0;
}

FILE* fileValidation(FILE* file)
{    
    char fileName[fileLength];
    char fileNoExtName[fileNoExtLength];

    printf("Please enter an input file name without extension:\n");
    printf("The program will search for a .txt file with the name you provided\n");
    scanf("%s", fileNoExtName);

    snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

    file = fopen(fileName, "r");

    while(file == NULL)
    {
        printf("File not found. Please enter an input file name without extension:\n");
        printf("The program will search for a .txt file with the name you provided\n");
        scanf("%s", fileNoExtName);
    
        snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

        file = fopen(fileName, "r");
    }

    return file;
}

void inputRead(char*** text, FILE* input, int* size)
{
    *size = 1;

    (*text) = malloc(sizeof(char*) * (*size));

    int i = 0;


    while(!feof(input))
    {
        (*text)[i] = malloc(sizeof(char) * textLength);

        fgets((*text)[i], textLength, input);

        if(strlen((*text)[i]) == (textLength - 1) && fgetc(input) != '\n')
        {
            while(fgetc(input) != '\n' && !feof(input))
            {
                ;
            }
        }

        if(!feof(input))
        {
            i++;

            if(i >= (*size))
            {
                (*size)++;
                (*text) = realloc((*text), sizeof(char*) * (*size));
            }
        }
    }
}