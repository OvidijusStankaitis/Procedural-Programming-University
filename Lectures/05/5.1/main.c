#include <stdio.h>

//// A ////
#define l 10

int main()
{
    int A[l] = {0};
    int size = l;

    //// B ////
    for (int i = 0; i < l; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    //// C ////
    A[0] = 1;
    A[3] = 2;
    A[9] = 3;

    //// D ////
    for (int i = 2; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }

    size--;

    //// E ////
    for (int i = size; i > 7; i--)
    {
        A[i] = A[i - 1];
    }

    A[6] = 4;
    size++;

    //// F ////
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    //// G ////
    int x = 0, y = 0;
    printf("Masyvo elementui su indeksu x bus priskirta reiksme y. X priklauso nuo [0; 9]\n");
    printf("Iveskite x: ");
    scanf("%d", &x);

    while(x > 9 || x < 0)
    {
        printf("Ivestas x nepriklauso intervalui, veskite kita. X priklauso nuo [0; 9]\n");
        printf("Iveskite x: ");
        scanf("%d", &x);
    }

    printf("Iveskite y: ");
    scanf("%d", &y);

    A[x] = y;

    //// H ////
    printf("Elementas su indeksu x bus istrintas. X priklauso nuo [0; 9]\n");
    printf("Iveskite x: ");
    scanf("%d", &x);

    while(x > 9 || x < 0)
    {
        printf("Ivestas x nepriklauso intervalui, veskite kita. X priklauso nuo [0; 9]\n");
        printf("Iveskite x: ");
        scanf("%d", &x);
    }

    for (int i = x; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }

    size--;

    //// I ////
    printf("Reiksme y bus iterpta taip, kad jos indeksas butu x. X priklauso nuo [0; 9]\n");
    printf("Iveskite x: ");
    scanf("%d", &x);

    while(x > 9 || x < 0)
    {
        printf("Ivestas x nepriklauso intervalui, veskite kita. X priklauso nuo [0; 9]\n");
        printf("Iveskite x: ");
        scanf("%d", &x);
    }

    printf("Iveskite y: ");
    scanf("%d", &y);

    for (int i = size; i > x; i--)
    {
        A[i] = A[i - 1];
    }

    A[x] = y;
    size++;

    //// J ////
    for (int i = 0; i < l; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}