// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 2
// Variantas nr. - 5

#include <stdio.h>

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

    struct Coordinates C[n], OUT;

    smallestNumberMaximum(n, N, C);

    OUT.n = C[0].n;

    for (int i = 0; i < n; i++)
    {
        if(OUT.n < C[i].n)
        {
            OUT.n = C[i].n;
            OUT.x = C[i].x;
            OUT.y = C[i].y;            
        } 
    }
    
    printf("\nThe largest number amongst the smallest numbers in each line is: %d\n", OUT.n);
    printf("It's coordinates are: \n");
    printf("Row %d Collumn %d \n", OUT.x + 1, OUT.y + 1);

    return 0;
}

void smallestNumberMaximum(int n, int N[][n], struct Coordinates C[n])
{
    int min = 0;

    for (int i = 0; i < n; i++)
    {
        min = N[i][0];
        C[i].x = i;

        for (int u = 0; u < n; u++)
        {
            if(min > N[i][u])
            {
                min = N[i][u];
                C[i].y = u;
            }   

            else C[i].y = 0;
        }

        C[i].n = min;
    }
}