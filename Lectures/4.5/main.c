#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n = 0;
    bool loopStatus = true;

    while(loopStatus == true)
    {    
        printf("Ivekite teigima sveika skaiciu n.\n");
        
        if(scanf("%d", &n) != 1 || getchar() != '\n')
        {
            printf("Neteisingi duomenys, iveskite teigiama sveika skaiciu.\n");
            while(getchar() != '\n')
            {
                ;
            }
        }

        else
        {
            if(n < 0)
            {
                printf("Ivedete neigiama sveika skaiciu.\n");
            }

            else loopStatus = false;
        }
    }

    float A[n];
    printf("Ivekite n realiuju skaiciu\n");

    float max = 0, min = 0, sum = 0;

    for(int i = 0; i < n; i++)
    {
        while(scanf("%f", &A[i]) != 1 || getchar() != '\n')
        {
            printf("Neteisingi duomenys, iveskite realuji skaiciu.\n");
            while(getchar() != '\n')
            {
                ;
            }
        }

        sum += A[i];
    }

    max = A[0];
    min = A[0];

    for (int i = 0; i < n; i++)
    {
        if(max < A[i])
        {
            max = A[i];
        }

        if(min > A[i])
        {
            min = A[i];
        }
    }
    

    printf("Siu skaiciu sekos suma: %f, minimumas: %f, maksimumas: %f.\n", sum, min, max);

    return 0;
}