#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define fileLength 256
#define fileNoExtLength 252
#define textLength 256

FILE* fileValidation(FILE* file, char* mode);

void inputRead(char*** text, FILE* input, int* size);

void parsingInput(char*** out, char** text, int size);

void fileOutput(char** out, FILE* output, int size);

int main()
{
    FILE* input = NULL;
    FILE* output = NULL;

    char** text;
    char** out;

    int size = 0;

    printf("Please enter an input file name without extension:\n");
    input = fileValidation(input, "r");

    fseek(input, 0L, SEEK_END);
    if(ftell(input) == 0)
    {
        printf("Input file is empty, aborting program.\n");
        return 0;
    }
    fseek(input, 0L, SEEK_SET);

    printf("Please enter an output file name without extension:\n");
    output = fileValidation(output, "w");

    inputRead(&text, input, &size);

    parsingInput(&out, text, size);

    fileOutput(out, output, size);

    fclose(input);
    fclose(output);

    free(out);
    free(text);

    return 0;
}

FILE* fileValidation(FILE* file, char* mode)
{    
    char fileName[fileLength];
    char fileNoExtName[fileNoExtLength];

    printf("The program will search for a .txt file with the name you provided\n");
    scanf("%s", fileNoExtName);

    snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

    file = fopen(fileName, mode);

    while(file == NULL)
    {
        printf("File not found. Please enter a file name without extension:\n");
        printf("The program will search for a .txt file with the name you provided\n");
        scanf("%s", fileNoExtName);
    
        snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

        file = fopen(fileName, mode);
    }

    return file;
}

void inputRead(char*** text, FILE* input, int* size)
{
    *size = 1;

    (*text) = malloc(sizeof(char*) * (*size));

    int i = 0, n = 0;

    while(!feof(input))
    {
        (*text)[i] = malloc(sizeof(char) * textLength);

        fgets((*text)[i], textLength, input);

        n = strlen((*text)[i]);

        if(n < textLength)
        {
            (*text)[i] = realloc((*text)[i], sizeof(char) * (n + 1));
        }

        if((*text)[i][n - 1] == '\n')
        {
            (*text)[i][n - 1] = '\0';
        }

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

void parsingInput(char*** out, char** text, int size)
{
    int n = 0, i = 0;

    (*out) = malloc(sizeof(char*) * size);

    while(i < size)
    {
        int index = 0;

        char ARR[256];
        memset(ARR, 0, sizeof(ARR));

        char* token = strtok(text[i], " ");

        bool temp = false;

        while(token != NULL)
        {
            n = strlen(token);

            if(token[1] == token[n - 3])
            {
                temp = true;
                for(int u = 0; u < n; u++)
                {
                    ARR[index + u] = token[u];
                }

                index += strlen(token);

                ARR[index++] = ' ';                           
            }

            token = strtok(NULL, " ");
        }

        (*out)[i] = malloc(sizeof(char) * strlen(ARR));

        if(strlen(ARR) <= 2)
        {
            (*out)[i] = "-";
        }

        else 
        {
            for(int u = 0; u < strlen(ARR); u++)
            {
                (*out)[i][u] = ARR[u];
            }
        }
        i++;
    }   
}

void fileOutput(char** out, FILE* output, int size)
{
    for(int i = 0; i < size; i++)
    {
        fprintf(output, "%s\n", out[i]);
    }
}