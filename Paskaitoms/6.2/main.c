#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "lt_LT");

    FILE *in = NULL;
    in = fopen("in.txt", "r");

    double x = 0, temp = 0;
    bool loopStatus = true;
    int count = 0;

    printf("Programa praso pateikti faile in.txt realuji skaiciu nuo 10 iki 100 iskaitytinai\n");
    printf("Skaicius negali tureti daugiau triju skaiciu po kablelio\n");
    printf("Programa apskaiciuoja skaiciaus ilgi\n\n");
    printf("Iveskite i faila realuji skaiciu nuo 10 iki 1000 iskaitytinai, kuris turi nedaugiau 3 skaiciu po kablelio ir paspauskite enter klavisa:\n");

    getchar(); 

    while(loopStatus == true)
    {
        while(fscanf(in, "%lf", &x) != 1 || fgetc(in) != EOF|| x < 10 || x > 1000)
        {
            printf("Bloga ivestis. Iveskite i faila realuji skaiciu nuo 10 iki 1000 iskaitytinai, kuris turi nedaugiau 3 skaiciu po kablelio ir paspauskite enter klavisa:\n");
            
            fclose(in);
            getchar();
            in = fopen("in.txt", "r");
        }

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
    }

    printf("%lf\n", x);

    fclose(in);
}