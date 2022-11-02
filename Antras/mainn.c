// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 2
// Variantas nr. - 5

#include <stdio.h>

int smallestNumberMaximum(int n, int N[][n]);

void maxCoord(int n, int max, int N[][n]);

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

    int max = smallestNumberMaximum(n, N);

    printf("\nThe largest number amongst the smallest numbers in each line is: %d\n", max);
    printf("It's coordinates are: \n");

    maxCoord(n, max, N);

    return 0;
}

int smallestNumberMaximum(int n, int N[][n])
{
    int MIN[n], min = 0;

    for (int i = 0; i < n; i++)
    {
        min = N[i][0];

        for (int u = 0; u < n; u++)
        {
            if(min > N[i][u])
            {
                min = N[i][u];
            }   
        }

        MIN[i] = min;
    }

    int max = MIN[0];

    for (int i = 0; i < n; i++)
    {
        if(max < MIN[i])
        {
            max = MIN[i];
        }  
    }

    return max;
}

void maxCoord(int n, int max, int N[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            if(N[i][u] == max)
            {
                printf("Line %d, collumn %d\n", i + 1, u + 1);
            }
        } 
    }
}