// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 1
// Variantas nr. - 8

#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variables 
    int num = 1;
    int negOdd = 0;
    bool loopStatus = true;

    // Prompts the user to enter a whole number
    printf("Enter a whole number. If you wish to stop, enter 0.\n");

    // Runs the cycle while num != 0
    while(loopStatus == true)
    {
        // Validates if input is trully a whole number and not another symbol
        if(scanf("%d", &num) != 1 || getchar() != '\n')
        {
            printf("Wrong input, enter a whole number: \n");
            while(getchar() != '\n')
            {
                ;
            }
        }
        
        else
        {
            if(num == 0)
            {
                loopStatus = false;
            }

            else
            {
                // Checks if the number is odd and
                if(num % 2 != 0 && num < 0)
                {
                    negOdd++;
                }
                
                // Prompts user to enter another whole number
                printf("Enter another whole number. If you wish to stop, enter 0.\n");
            }
        }
    }

    // Displays the count of negative whole numbers
    printf("Count of negative odd numbers: %d \n", negOdd);

    return 0;
}
