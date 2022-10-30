#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void generateArray(long long int N[], long long int n, long long int min, long long int max);

int main()
{
    srand (time(NULL)); 
    long long int n = 0, min = 0, max = 0;
    bool loopStatus = true;

    printf("Iveskite kokio dydzio masyvo norite. Tada iveskite min ir max rezius tarp kuriu bus generuojami random skaiciai ir dedami i masyva\n");

    while(loopStatus)
    {
        while(scanf("%lld", &n) != 1 || getchar() != '\n')
        {
            printf("Bloga ivestis. Iveskite sveika skaiciu, kuri norite tikrinti.\n");

            while(getchar() != '\n')
            {
                ;
            }
        }

        while(scanf("%lld", &min) != 1 || getchar() != '\n')
        {
            printf("Bloga ivestis. Iveskite sveika skaiciu Min.\n");

            while(getchar() != '\n')
            {
                ;
            }
        }

        while(scanf("%lld", &max) != 1 || getchar() != '\n')
        {
            printf("Bloga ivestis. Iveskite sveika skaiciu Max.\n");

            while(getchar() != '\n')
            {
                ;
            }
        }

        if(n == 9223372036854775807 || max == 9223372036854775807 || min == 9223372036854775807)
        {
            printf("Ivestas per ilgas skaicius arba skaiciai, veskite is naujo.\n");
        }

        else if(max < min)
        {
            printf("Max turi buti didesnis uz Min. Veskite is naujo.");
        }

        else
        {
            loopStatus = false;
        }
    }

    printf("\n");

    long long int N[n];

    generateArray(N, n, min, max);

    for(int i = 0; i < n; i++)
    {
        printf("%lld\n", N[i]);
    }

    return 0;
}

void generateArray(long long int N[], long long int n, long long int min, long long int max)
{
    for(int i = 0; i < n; i++)
    {
        N[i] = (rand() % (max - min + 1)) + min;
    }
}