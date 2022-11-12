#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int* generateArray();

int main()
{
    srand (time(NULL)); 

    printf("Iveskite kokio dydzio masyvo norite. Tada iveskite min ir max rezius tarp kuriu bus generuojami random skaiciai ir dedami i masyva\n");

    printf("\n");

    int* N = generateArray();

    printf("\n");

    if(N == NULL)
    {
        printf("Nepavyko sugeneruoti masyvo.\n");
        return 0;
    }

    else
    {
        for(int i = 0; N[i]!='\0'; i++)
        {
            printf("%lld\n", N[i]);
        }

        return 0;
    }
}

int* generateArray()
{
    int n = 0, min = 0, max = 0;

    scanf("%d %d %d", &n, &min, &max);

    if(min >= max)
    {
        return NULL;
    }

    else
    {
        int *N = malloc(sizeof(n));

        for(int i = 0; i < n; i++)
        {
            N[i] = (rand() % (max - min + 1)) + min;
        }

        return N;
    }
}