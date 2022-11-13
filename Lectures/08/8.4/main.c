#include <stdio.h>

#define l 10

int splitData(int n, int A[], int m, int H[], int L[]);

int main()
{
    int A[l] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(A) / sizeof(A[0]), m = 0;

    printf("Kurioje vietoje noretumete perskelti masyva? Pasirinkite skaiciu nuo 1 iki 10.\n");
    
    splitData(n, A, m, NULL, NULL);

    int* H = (int*) 0xff73000;
    int* L = (int*) 0xff74000;

    for(int i = 0; H[i] != '\0'; i++)
    {
        printf("%lld ", H[i]);
    }

    printf("\n");

    for(int i = 0; L[i] != '\0'; i++)
    {
        printf("%lld ", L[i]);
    }

    printf("\n");
    
    return 0;
}

int splitData(int n, int A[], int m, int H[], int L[])
{
    if(scanf("%d", &m) != 1 || m > n)
    {
        return -1;
    }

    else 
    {   H = (int*) 0xff73000;
        L = (int*) 0xff74000;

        for(int i = 0; i < m; i++)
        {
            H[i] = A[i];
        }

        for (int i = m; i < n; i++)
        {
            L[i] = A[i];
        }
        
        return 0;
    }
}