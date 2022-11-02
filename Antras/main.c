// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 2
// Variantas nr. - 5

#include <stdio.h>
#include <stdbool.h>

struct Coordinates
{
    int n;
    int x;
    int y;
};

void smallestNumberMaximum(int n, int N[][n], struct Coordinates C[n]);

int main()
{
    int n = 0;

    printf("Enter a positive whole number n:\n");

    while(scanf("%d", &n) != 1 || getchar() != '\n' || n <= 0)
    {
        printf("Wrong input, enter a positive whole number:\n");
        while(getchar() != '\n')
        {
            ;
        }
    }

    int N[n][n];

    printf("Enter %d whole number(s) to fill the table:\n", n*n);

    for(int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            while(scanf("%d", &N[i][u]) != 1 || getchar() != '\n')
            {
                printf("Wrong input, enter a whole number: \n");
                while(getchar() != '\n')
                {
                    ;
                }
            }
        }
    }

    struct Coordinates C[n]; 
    
    int OUT = 0;

    smallestNumberMaximum(n, N, C);

    OUT = C[0].n;

    for (int i = 0; i < n; i++)
    {
        if(OUT < C[i].n)
        {
            OUT = C[i].n;         
        } 
    }
    
    printf("\nThe largest number amongst the smallest numbers in each line is: %d\n", OUT);
    printf("It's coordinates are: \n");
    
    for(int i = 0; i < n; i++)
    {
        if(C[i].n == OUT)
        {
            printf("Row %d Collumn %d \n", C[i].x + 1, C[i].y + 1);
        }
    }

    return 0;
}

void smallestNumberMaximum(int n, int N[][n], struct Coordinates C[n])
{
    int min = 0;

    bool status = true;

    for (int i = 0; i < n; i++)
    {
        min = N[i][0];
        C[i].x = i;
        status = true;

        for (int u = 0; u < n; u++)
        {
            if(min > N[i][u])
            {
                min = N[i][u];
                C[i].y = u;
                status = false;
            }   

            else if(status == true) C[i].y = 0;
        }

        printf("\n%d\n",C[i].y);

        C[i].n = min;
    }
}