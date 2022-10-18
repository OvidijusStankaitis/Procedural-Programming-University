#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    FILE *in = NULL;
    setlocale(LC_ALL, "lt_LT.utf8");

    double x = 0, temp = 0;

    bool loopStatus = true;

    int count = 0;

    printf("Programa praso pateikti faile in.txt realuji skaiciu nuo 10 iki 100 iskaitytinai\n");
    printf("Skaicius negali tureti daugiau triju skaiciu po kablelio\n");
    printf("Programa apskaiciuoja skaiciaus ilgi\n\n");
    printf("Iveskite i faila realuji skaiciu nuo 10 iki 1000 iskaitytinai, kuris turi nedaugiau 3 skaiciu po kablelio ir paspauskite enter klavisa:\n");

    getchar(); 

    in = fopen("in.txt", "r");

    while(loopStatus == true)
    {
        if(fscanf(in, "%lf", &x) != 1 || fgetc(in) != EOF|| x < 10 || x > 1000)
        {
            printf("Bloga ivestis. Iveskite i faila realuji skaiciu nuo 10 iki 1000 iskaitytinai, kuris turi nedaugiau 3 skaiciu po kablelio ir paspauskite enter klavisa:\n");
            
            getchar();
            fclose(in);
            in = fopen("in.txt", "r");
        }
        
        else 
        {
            count = 0;

            temp = x;

            while(temp!=((int)temp))
            {
                count++;
                temp=temp*10;
            }

            if(count <= 3)
            {
                loopStatus = false;
            }

            else
            {
                printf("Bloga ivestis. Iveskite i faila realuji skaiciu nuo 10 iki 1000 iskaitytinai, kuris turi nedaugiau 3 skaiciu po kablelio ir paspauskite enter klavisa:\n");
                getchar();
                fclose(in);
                in = fopen("in.txt", "r");
            }
        }
    }

    int temp2 = ((int)x);
    
    while(temp2 != 0)
    {
        temp2 = temp2 / 10;
        count++;
    }

    printf("%d\n", count);

    fclose(in);

    return 0;
}