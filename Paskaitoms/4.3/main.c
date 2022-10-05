#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a = 0, b = 0, c = 0;
    bool loopStatus = true;

    while(loopStatus == true)
    {    
        printf("Iveskite tris neneigiamus sveikuosius skaicius.\n");
        
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
            if(a < 0 || b < 0 || c < 0)
            {
                printf("Ivedete bent viena neigiama sveika skaiciu.\n");
            }

            else loopStatus = false;
        }
    }

    long long int F[c];
    F[0] = a;
    F[1] = b;

    for(int i = 2; i <= c; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }

    printf("c-asis skaicius fc = %lld\n", F[c]);

    return 0;
}