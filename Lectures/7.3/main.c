#include <stdio.h>
#include <stdbool.h>

long long int getPositiveNumber(char *msg);

int main()
{
    long long int num = 0;

    char msg[] = "Iveskite teigima sveika skaiciu: \n";
    
    num = getPositiveNumber(msg);

    printf("Skaicius: %lld\n", num);

    return 0;
}

long long int getPositiveNumber(char *msg)
{
    long long int num = 0;
    bool loopStatus = true;

    printf("%s", msg);

    while(loopStatus)
    {
        if(scanf("%lld", &num) != 1 || getchar() != '\n' || num < 1)
        {
            printf("%s", msg);
            while(getchar() != '\n')
            {
                ;
            }
        }

        else loopStatus = false;
    }

    return num;
}