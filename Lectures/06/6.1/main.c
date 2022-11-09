#include <stdio.h>

int main()
{
    FILE *out = NULL;

    out = fopen("out.txt","w");

    printf("Programa papraso ivesti sveika skaiciu, apskaiciuoja jo faktoriala ir atsakyma isveda i ekrana ir i faila out.txt\n");
    printf("Iveskite sveika skaiciu:\n");

    int x = 0;
    long long int faktorialas = 1; 

    while(scanf("%d", &x) != 1 || getchar() != '\n')
    {
        printf("Bloga ivestis, iveskite sveika skaiciu: \n");
        while(getchar() != '\n')
        {
            ;
        }
    }

    for(int i = 1; i <= x; i++)
    {
        faktorialas = faktorialas * i;
    }

    printf("Skaiciaus %d faktorialas yra %lld\n", x, faktorialas);
    fprintf(out, "Skaiciaus %d faktorialas yra %lld", x, faktorialas);

    fclose(out);

    return 0;
}