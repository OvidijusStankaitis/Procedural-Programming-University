#include <stdio.h>
#include <stdbool.h>

bool isInRange(int num, int min, int max);

int main()
{
    long long int num = 0, min = 0, max = 0;

    int count = 0;

    bool loopStatus = true;

    printf("Iveskite tris skaicius.\n1. Skaicius, kuri norite patikrinti\n2. Intervalo minimalus (min) rezis\n3. Intervalo maksimalus (max) rezis\n");

    while(loopStatus)
    {
        while(scanf("%lld", &num) != 1 || getchar() != '\n')
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

        if(num == 9223372036854775807 || max == 9223372036854775807 || min == 9223372036854775807)
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

    if(isInRange(num, min, max) == true)
    {
        printf("Skaicius %lld patenka i intervala [%lld; %lld]\n", num, min, max);
    }

    else printf("Skaicius %lld nepatenka i intervala [%lld; %lld]\n", num, min, max);

    return 0;
}

bool isInRange(int num, int min, int max)
{
    if(num <= max && num >= min)
    {
        return true;
    }

    else return false;
}