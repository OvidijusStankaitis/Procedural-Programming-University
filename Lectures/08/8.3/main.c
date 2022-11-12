#include <stdio.h>

void swap(int* x, int* y);

int main()
{
    int x = 0, y = 0;
    
    printf("Iveskite du sveikus skaicius\n");
    scanf("%d %d", &x, &y);

    printf("Pries apkeitima: %d %d\n", x, y);

    swap(&x, &y);

    printf("Po apkeitimo: %d %d\n", x, y);

    return 0;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}