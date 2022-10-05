#include <stdio.h>
#include <math.h>

int main()
{
    printf("Iveskite tris sveikus skaicius.\n");
    int A[3] = {0};

    while(scanf("%d %d %d",&A[0], &A[1], &A[2]) != 3 || getchar() != '\n')
    {
        printf("Neteisingi duomenys, iveskite tris sveikus skaicius: \n");
        while(getchar() != '\n')
        {
            ;
        }
    }
    
    int D = 0;
    D = pow(A[1], 2) - 4 * A[0] * A[2];

    float x = 0, x1 = 0, x2 = 0;

    if(D < 0)
    {
        printf("Kvadratine lygtis sprendiniu neturi.\n");
        return 0;
    }

    else if(D == 0)
    {
        printf("Kvadratine lygtis turi viena sprendini. Jis yra: \n");

        x = (-1 * A[1]) / (2 * A[0]);
        printf("x = %f\n", x);

        return 0;
    }

    else 
    {
        printf("Kvadratine lygtis turi du sprendinius. Jie yra: \n");

        x1 = ((-1 * A[1]) - sqrt(D)) / (2 * A[0]);
        x2 = ((-1 * A[1]) + sqrt(D)) / (2 * A[0]);
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);

        return 0;
    }
}