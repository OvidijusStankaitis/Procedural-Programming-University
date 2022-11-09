#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define l 3

int main()
{
    FILE *out = NULL;

    long long int num[l] = {0};

    char trash1 = ' ', trash2 = ' ';

    bool loopStatus = true;

    printf("Programa papraso vartotojo ivesti tris sveikus skaicius atskirtus kabliataskiais, suranda ir \n");
    printf("faile, kurio pavadinima reikia ivesti su pletiniu \".txt.\", atspausdina viduriniji is ivestu skaiciu pagal reiksme.\n");
    printf("Iveskite tris sveikus skaicius atskirtus kabliataskiais.\n");

    while(loopStatus)
    {
        char input[65535] = {' '};

        scanf("%s", &input);

        if(sscanf(input, "%lld%c%lld%c%lld", &num[0], &trash1, &num[1], &trash2, &num[2]) != 5 || trash1 != ';' || trash2 != ';')
        {
            printf("Bloga ivestis. Iveskite tris sveikus skaicius be tarpu, kurie yra atskirti kabliataskiais.\n");

            while(getchar() != '\n')
            {
                ;
            }
        }

        else if(num[0] == 9223372036854775807 || num[1] == 9223372036854775807 || num[2] == 9223372036854775807)
        {
            printf("Ivestas per ilgas skaicius arba skaiciai, veskite is naujo.\n");
        }

        else
        {
            loopStatus = false;
        }
    }

    int temp = 0;

    for (int i = 0; i < l; i++)
    {
        for (int u = i; u < l; u++)
        {
            if(num[i] < num[u])
            {
                temp = num[i];
                num[i] = num[u];
                num[u] = temp;
            }
        }
    }

    char fileName[256];

    loopStatus = true;

    int fileNameLength = 0;

    printf("Iveskite failo pavadinima, kurio pletinys yar \".txt.\" \n");

    while (loopStatus)
    {
        scanf("%s", &fileName);

        fileNameLength = strlen(fileName);

        if(fileName[fileNameLength - 1] != 't' || fileName[fileNameLength - 2] != 'x' || fileName[fileNameLength - 3] != 't' || fileName[fileNameLength - 4] != '.')
        {
            printf("Failo pletinys turi buti \".txt\"\n");
        }

        else loopStatus = false;
    }
    
    out = fopen(fileName, "w");
    fprintf(out, "%lld\n", num[1]);
    
    return 0;
}