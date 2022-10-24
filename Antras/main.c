// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 2
// Variantas nr. - 5

#include <stdio.h>

void MinMaxCoor(int n, int N[n][n], struct NumCoor *MIN, struct NumCoor *MAX);

struct NumCoor
{
    int n;
    int y;
};

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

    struct NumCoor MIN[n], MAX[n];

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

    MinMaxCoor(n, N, MIN, MAX);

    for(int i = 0; i < n; i++)
    {
        printf("\nIn line number %d the maximum number was %d inside collumn %d, the minimum number was %d inside collumn %d\n",
               i + 1, MAX[i].n, MAX[i].y, MIN[i].n, MIN[i].y);
    }

    return 0;
}

void MinMaxCoor(int n, int N[n][n], struct NumCoor *MIN, struct NumCoor *MAX)
{
    for(int i = 0; i < n; i++)
    {
        MIN[i].n = N[i][0];
        MIN[i].y = 1;

        MAX[i].n = N[i][0];
        MAX[i].y = 1;

        for(int u = 1; u < n; u++)
        {
            if(MIN[i].n > N[i][u])
            {
                MIN[i].n = N[i][u];
                MIN[i].y = u + 1;
            }

            if(MAX[i].n < N[i][u])
            {
                MAX[i].n = N[i][u];
                MAX[i].y = u + 1;
            }
        }
    }
}