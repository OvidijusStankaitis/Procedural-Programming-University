#include <stdio.h>

int main()
{
    /// Vertimas is dvejetaines is desimtaine
    printf("Dvejetainiai skaiciai 11011, 10010100, 11001011010101 paversti i desimtainius: \n");
    long B[3] = {11011, 10010100, 11001011010101};
    int liekana = 0, desimtainis = 0, svoris = 1;
    int n = 3;

    for (int i = 0; i < n; ++i)
    {
        desimtainis = 0;
        svoris = 1;
        liekana = 0;

        while(B[i] != 0)
        {
            liekana = B[i] % 10;
            desimtainis = desimtainis + liekana * svoris;
            B[i] = B[i] / 10;
            svoris = svoris * 2;
        }
        printf("%d ", desimtainis);
    }
    printf("\n\n");

    /// Vertimas is desimtaines i dvejetaine
    printf("Desimtainiai skaiciai 37, 241, 2487 paversti i dvejetainius: \n");
    int Desimtainis[3] = {37, 241, 2487};
    int x = 0;

    for(int i = 0; i < n; i++)
    {
        int DvejetainisSkaicius[32] = {0};
        x = 0;

        while (Desimtainis[i] > 0)
        {
            DvejetainisSkaicius[x] = Desimtainis[i] % 2;
            Desimtainis[i] = Desimtainis[i] / 2;
            x++;
        }

        for (int j = x - 1; j >= 0 ; j--)
        {
            printf("%d", DvejetainisSkaicius[j]);
        }
        printf(" ");
    }
    printf("\n\n");

    /// Vertimas is sesioliktaines i desimtaine
    printf("Sesioliktainiai skaiciai 6E2, ED33, 123456 paversti i desimtainius: \n");
    int H[3] = {0x6E2, 0xED33, 0x1234};
    
    for(int i = 0; i < n; i++)
    {
    	printf("%d ", H[i]);
    }
    printf("\n\n");

    /// Vertimas is desimtaines i sesioliktaine
    printf("Desimtainiai skaiciai 243, 2483, 4612 paversti i sesioliktainius: \n");
    int D[3] = {243, 2483, 4612};    
    
    for(int i = 0; i < n; i++)
    {
    	printf("0x%X ", D[i]);
    }
    printf("\n\n");
    
    return 0;
}
