#include <stdio.h>

long int fakt(int num);

int main()
{
    int num = 0;

    printf("Programa skaiciuoja skaiciaus faktoriala. Ieskite 0 arba sveika skaiciu, kuris yra didesnis arba lygus vienetui\n");

    while(scanf("%d", &num) != 1 || getchar() != '\n' || num < 0 || num > 0 && num < 1)
    {
        printf("Bloga ivestis. Ieskite 0 arba svaika skaiciu, kuris yra didesnis arba lygus vienetui\n");
        while(getchar() != '\n')
        {
            ;
        }
    }

    printf("Skaiciaus %d faktorialas yra: %ld\n", num, fakt(num));
    
    return 0;
}

long int fakt(int num)
{
    if (num >= 1)
        return num * fakt(num - 1);
    else
        return 1;
}