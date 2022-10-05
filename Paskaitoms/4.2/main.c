#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool loopStatus = true;
    int a = 0, b = 0, c = 0;
    int arrSize = 0;

    printf("Programa skaiciuoja kiek skaiciu yra intervale (a; b], kurie dalinasi is c su liekana 1.\n");

    while(loopStatus == true)
    {
        printf("Iveskite tris sveikus skaicius.\n");

        if(scanf("%d %d %d", &a, &b, &c) != 3 || getchar() != '\n')
        {
            printf("Neteisingi duomenys, iveskite tris sveikus skaicius: \n");
            while(getchar() != '\n')
            {
                ;
            }
        }

        else 
        {
            if(a > b)
            {
                printf("Intervalas negalimas. Skaicius a turi buti maziau uz b (a < b), kad susidarytu intervalas (a; b].\n");
            }

            else loopStatus = false;
        }
    }

    arrSize = b - a;

    int A[arrSize];
    int temp = a;
    for(int i = 0; i < arrSize; i++)
    {
        temp += 1;
        A[i] = temp;
    }

    printf("Skaiciai, kurie intervale (%d; %d] dalinasi is %d su liekana 1:\n",a ,b, c);

    int help = 0;

    for (int i = 0; i < arrSize; i++)
    {
        if(A[i] % c == 1)
        {
            printf("%d ", A[i]);
            help++;
        }
    }

    if(help == 0)
    {
        printf("Tokiu skaiciu nera.\n");
    }

    else 
    {
        printf("\n");
    }

    return 0;
}