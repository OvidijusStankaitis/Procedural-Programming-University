#include <stdio.h>

int largeFile(int argCount, char* argName[]);

int main(int argCount, char* argName[])
{
    int index = 0;

    if(argCount == 1)
    {
        printf("Nera failu\n");
        return 0;
    }

    else
    {
        index = largeFile(argCount, argName);
        printf("Didziausias failas yra: %s\n", argName[index]);
    }

    return 0;
}

int largeFile(int argCount, char* argName[])
{
    FILE* file = NULL;
    size_t size = 0, max = 0;
    int index = 0;

    for(int i = 1; i < argCount; i++)
    {
        file = fopen(argName[i], "rb");

        if(file != NULL)
        {
            fseek(file, 0, SEEK_END);
            size = ftell(file);

            if(size > max)
            {
                max = size;
                index = i;
            }
        }

        else printf("Failo %s nera.\n", argName[i]);
    }

    return index;
}