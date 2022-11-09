#include <stdio.h>

int main()
{   
    printf("Programa praso ivesti teigiamus skaicius s ir n. Paskui praso ivesti n teigiamu skaiciu. Baigus vesti randa skaiciu poras, kuriu sandauga lygi s.\n");

    int s = 0, n = 0;

    printf("Iveskite teigiama skaiciu s: ");

    scanf("%d", &s);
    while(s <= 0)
    {
        printf("Netesinga ivestis, s turi buti daugiau uz 0. Veskite s dar kart\n");
        scanf("%d", &s);
    }

    printf("Iveskite teigiama skaiciu n: ");
    scanf("%d", &n);
    while(n <= 0)
    {
        printf("Netesinga ivestis, n turi buti daugiau uz 0. Veskite n dar kart\n");
        scanf("%d", &n);
    }

    int X[n];

    printf("\nIveskite %d teigiamu(s) skaiciu(s):\n", n);

    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        scanf("%d", &temp);

        while(temp <= 0)
        {
            printf("Netesinga ivestis, skaicius turi buti daugiau uz 0. Veskite skaiciu dar kart\n");
            scanf("%d", &temp);
        }   

        X[i] = temp;
    } 

    printf("\nSkaiciu poros, kurias sudauginus gaunasi %d:\n", s);

    for(int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(X[i] * X[j] == s)
            {
                printf("%d %d\n", X[i], X[j]);
            }
        } 
    }

    return 0;
}