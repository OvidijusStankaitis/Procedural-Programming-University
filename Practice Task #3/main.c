// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 3
// Variantas nr. - 5

// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants
#define fileLength 256
#define fileNoExtLength 252
#define textLength 256

// Function/Procedure declarations
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

    // Prompts user to enter input file name and checks if it exits or not adn opens it
    printf("Please enter an input file name without extension:\n");
    input = fileValidation(input, "r");

    // Checks if file is empty, if it is - program is aborted
    fseek(input, 0L, SEEK_END);
    if(ftell(input) == 0)
    {
        printf("Input file is empty, aborting program.\n");
        return 0;
    }
    fseek(input, 0L, SEEK_SET);

    // Prompts user to enter output file name, if it exits - opens file if not - creates a file
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

    // Joins entered file name with no extension wit ".txt"
    snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

    file = fopen(fileName, mode);

    // Checks if file was opened
    while(file == NULL)
    {
        printf("File not found. Please enter a file name without extension:\n");
        printf("The program will search for a .txt file with the name you provided\n");
        scanf("%s", fileNoExtName);
    
        snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

        file = fopen(fileName, mode);
    }

    // Returns the file
    return file;
}

void inputRead(char*** text, FILE* input, int* size)
{
    *size = 1;

    // Allocates 1 line to the buffer
    (*text) = malloc(sizeof(char*) * (*size));

    int i = 0, n = 0;

    // While not EOF
    while(!feof(input))
    {
        // Allocates 256 chars to a line
        (*text)[i] = malloc(sizeof(char) * textLength);

        fgets((*text)[i], textLength, input);

        n = strlen((*text)[i]);

        // If text length is less than 255, buffer is reduced to n chars
        if(n < (textLength - 1))
        {
            (*text)[i] = realloc((*text)[i], sizeof(char) * (n + 1));
        }

        // Endline is replaced with a string end symbol
        if((*text)[i][n - 1] == '\n')
        {
            (*text)[i][n - 1] = '\0';
        }

        // If line has more than 255 symbols it ignores it
        if(strlen((*text)[i]) == (textLength - 1) && fgetc(input) != '\n')
        {
            while(fgetc(input) != '\n' && !feof(input))
            {
                ;
            }
        }

        // Allocates +1 line to the dynamic buffer if not EOF
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

    // Allocating the number of lines to the dynamic buffer
    (*out) = malloc(sizeof(char*) * size);

    while(i < size)
    {
        int index = 0;

        char ARR[256];
        memset(ARR, 0, sizeof(ARR));

        // Separating string into tokens of a single word
        char* token = strtok(text[i], " ");

        while(token != NULL)
        {
            n = strlen(token);

            // Checks if the second element is the same as the third one from the back
            if(token[1] == token[n - 3])
            {
                // Puts it inside a static array of 256 so that we can
                // put elements that are in one line back into a single line
                for(int u = 0; u < n; u++)
                {
                    ARR[index + u] = token[u];
                }

                index += strlen(token);

                // Adds a space after a word
                ARR[index++] = ' ';                           
            }

            // Moves to the next token
            token = strtok(NULL, " ");
        }

        // Allocates the number of characters inside ARR to a line
        (*out)[i] = malloc(sizeof(char) * strlen(ARR));

        // If there are no elemts that pass the condition a minus is moved into output buffer
        if(strlen(ARR) <= 2)
        {
            (*out)[i] = "-";
        }

        // The elements that pass the condition ar moved into the output buffer
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