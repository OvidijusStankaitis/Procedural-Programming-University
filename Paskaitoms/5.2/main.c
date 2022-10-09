#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define l 1000

int main()
{
    int A[l] = {0};
    int a = 0, b = 0, c = 0;

    srand (time(NULL)); 

    printf("Iveskite 3 skaicius. a, b, c. Programa atspausdins c random sugeneruotu skaiciu intervale [a; b], a < b, c <= 1000\n");
    scanf("%d %d %d", &a, &b, &c);

    while(b < a)
    {
        printf("Neteisingi masyvo reziai. a turi buti maziau uz b. Veskite a ir b is naujo");
        scanf("%d %d", &a, &b);
    }

    while(c > 1000)
    {
        printf("Bus generuojama perdaug reiskiniu, netilps i masyva. c turi buti maziau uz 1000. Veskite c is naujo");
        scanf("%d", &c);
    }

    printf("\n");

    for(int i = 0; i < c; i++)
    {
        A[i] = (rand() % (b - a + 1)) + a;
    }

    for(int i = 0; i < c; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}