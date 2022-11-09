#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define l 1000

int main()
{
    printf("Programa praso ivesti skaicius a, b ir c. Intervale [a; b] sugeneruoja c random skaiciu. a < b, 0 < c <= 1000\n\n");

    int A[l] = {0};
    int a = 0, b = 0, c = 0;

    srand (time(NULL)); 
    
    printf("Iveskite a ir b:\n");
    scanf("%d %d", &a, &b);

    while(b < a)
    {
        printf("Neteisingi masyvo reziai. a turi buti maziau uz b. Veskite a ir b is naujo:\n");
        scanf("%d %d", &a, &b);
    }

    printf("Iveskite c:\n");
    scanf("%d", &c);
    while(c > 1000)
    {
        printf("Bus generuojama perdaug reiskiniu, netilps i masyva. c turi buti maziau uz 1000. Veskite c is naujo:\n");
        scanf("%d", &c);
    }

    while(c <= 0)
    {
        printf("c negali buti mazesnis arba lygus 0. Veskite c is naujo:\n");
        scanf("%d", &c);
    }

    printf("\n");

    for(int i = 0; i < c; i++)
    {
        A[i] = (rand() % (b - a + 1)) + a;
    }

    printf("Sugeneruoti skaiciai\n");

    for(int i = 0; i < c; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}