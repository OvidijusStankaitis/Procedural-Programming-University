// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 2
// Variantas nr. - 5

#include <stdio.h>
#include <stdbool.h>

// Data structure that holds values of the smallest number in the line
// and x ; y coordinates of that number
struct Coordinates
{
    int n;
    int x;
    int y;
};

// Declaring a function that finds the smallest number in each line
void smallestNumbers(int n, int N[][n], struct Coordinates C[n]);

// Declaring a function that validates user input
int Validation(int n);

int main()
{
    int n = 0, m = 0; 
    bool loopStatus = true;

    // Prompting user to enter one whole positive number and chacking their input
    printf("Enter a positive whole number n:\n");

    while(loopStatus)
    {
        n = Validation(n);

        if(n <= 0)
        {
            printf("Wrong input, enter a positive whole number:\n");
        }

        else loopStatus = false;
    }
    

    int N[n][n];

    // Prompting user to enter n * n whole numbers and chacking their input(s)
    printf("Enter %d whole number(s) to fill the table:\n", n*n);

    for(int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            m = Validation(m);

            N[i][u] = m;
        }
    }

    // Checking if the array is filled with the same number
    bool printStatus = true;

    int checking = N[0][0];

    for(int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            if(checking != N[i][u])
            {
                printStatus = false;
                break;
            }
        }

        if(printStatus == false) 
        {
            break;
        }
    }

    // If the array is filled with the same number, program prints out a message and terminates
    if(printStatus)
    {
        printf("All numbers are equal\n");
        return 0;
    }

    struct Coordinates C[n]; 
    
    int OUT = 0;

    // Calling a function that finds the smallest number in each line
    smallestNumbers(n, N, C);

    OUT = C[0].n;

    // Finding the largest number amongst the smallest ones
    for (int i = 0; i < n; i++)
    {
        if(OUT < C[i].n)
        {
            OUT = C[i].n;         
        } 
    }

    // Printing which number was the maximum of minimums
    printf("\nThe largest number amongst the smallest numbers in each line is: %d\n", OUT);
    printf("It's coordinates are: \n");
    
    // Printing the coordinates of the number
    for(int i = 0; i < n; i++)
    {
        if(C[i].n == OUT)
        {
            printf("Row %d Collumn %d \n", C[i].x + 1, C[i].y + 1);
        }
    }

    return 0;
}

// A function that finds the smallest number in each line
void smallestNumbers(int n, int N[][n], struct Coordinates C[n])
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

        C[i].n = min;
    }
}

// A function that validates user input
int Validation(int n)
{
    while(scanf("%d", &n) != 1 || getchar() != '\n')
    {
        printf("Wrong input, enter a positive whole number:\n");
        while(getchar() != '\n')
        {
            ;
        }
    }

    return n;
}