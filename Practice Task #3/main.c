#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fileLength 256
#define fileNoExtLength 252
#define textLength 256

FILE* fileValidation(FILE* file);

void inputRead(char*** text, FILE* input, int* size);

void parsingInput(char*** out, char** text, int size);

int main()
{
    FILE* input = NULL;

    char** text;
    char** out;

    int size = 0;

    input = fileValidation(input);

    inputRead(&text, input, &size);

    parsingInput(&out, text, size);

    // for(int i = 0; i < size; i++)
    // {
    //     printf("%s\n", out[i]);
    // }

    fclose(input);

    free(out);
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

        char* token = strtok(text[i], " ");

        while(token != NULL)
        {
            n = strlen(token);

            if(token[1] == token[n - 3])
            {
                for(int u = 0; u < n; u++)
                {
                    ARR[index + u] = token[u];
                }

                index += n;

                ARR[index++] = ' ';                           
            }

            token = strtok(NULL, " ");
        }

        (*out)[i] = malloc(sizeof(char) * strlen(ARR));

        if(strlen(ARR) == 0)
        {
            (*out)[i] = "-";
        }

        else 
        {
            (*out)[i] = ARR;
        }

        printf("%s\n", ARR);

        memset(ARR, 0, sizeof(ARR));

        // printf("%s\n", ARR);

        i++;
    }   

    // for(int i = 0; i < size; i++)
    // {
    //     printf("%s\n", (*out)[i]);
    // }
}