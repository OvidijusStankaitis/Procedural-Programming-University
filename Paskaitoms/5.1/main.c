#include <stdio.h>

#define l 10

int main()
{
    int A[l] = {0};
    int size = l;

    for (int i = 0; i < l; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n\n");

    A[0] = 1;
    A[3] = 2;
    A[9] = 3;

    for (int i = 2; i <= size - 2; i++)
    {
        A[i] = A[i + 1];
    }

    size--;

    for (int i = size; i > 7; i--)
    {
        A[i] = A[i - 1];
    }

    A[6] = 4;
    size++;

    for (int i = 0; i < l; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n\n");

    int x = 0, y = 0;
    printf("Iveskite 2 skaicius x ir y. X priklauso nuo [0; 9]\n");
    scanf("%d%d", &x, &y);

    while(x > 9)
    {
        printf("Ivestas x nepriklauso intervalui, veskite kita. X priklauso nuo [0; 9]\n");
        scanf("%d", &x);
    }

    A[x] = y;

    printf("Iveskite skaiciu x. X priklauso nuo [0; 9]\n");
    scanf("%d", &x);

    while(x > 9)
    {
        printf("Ivestas x nepriklauso intervalui, veskite kita. X priklauso nuo [0; 9]\n");
        scanf("%d", &x);
    }

    for (int i = x; i <= size - x; i++)
    {
        A[i] = A[i + 1];
    }

    size--;

    printf("Iveskite 2 skaicius x ir y. X priklauso nuo [0; 9]\n");
    scanf("%d%d", &x, &y);

    while(x > 9)
    {
        printf("Ivestas x nepriklauso intervalui, veskite kita. X priklauso nuo [0; 9]\n");
        scanf("%d", &x);
    }

    for (int i = size; i > x; i--)
    {
        A[i] = A[i - 1];
    }

    A[x] = y;
    size++;

    for (int i = 0; i < l; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}