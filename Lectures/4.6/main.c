#include <stdio.h>
#include <stdbool.h>

struct Skaicius
{
    int n;
    int d;
};

int main()
{
    bool loopStatus = true;
    int digits = 0;
    int num = 0, temp = 0;
    struct Skaicius S;

    printf("Iveskite skaiciu, jei norite baigti vesti, iveskite neigiama skaiciu.\n");

    while(loopStatus == true)
    {
        if(scanf("%d", &num) != 1 || getchar() != '\n')
        {
            printf("Neteisingi duomenys, iveskite skaiciu.: \n");
            while(getchar() != '\n')
            {
                ;
            }
        }
        
        else
        {
            digits = 0;
            
            if(num < 0)
            {
                loopStatus = false;
            }

            else
            {
                temp = num;
                while(temp!=0)            
                {  
                    temp=temp/10;  
                    digits++;  
                } 
                printf("Iveskite kita skaiciu, jei norite baigti vesti, iveskite neigiama skaiciu.\n");
            }
        }

        if(digits > S.d)
        {
            S.d = digits;
            S.n = num;
        }
    }

    printf("Daugiausiai skaitmenu turi skaicius %d: %d\n", S.n, S.d);

    return 0;
}