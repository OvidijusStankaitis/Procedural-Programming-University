#include <stdio.h>

int main()
{
    long long int a = 0, b = 0, c = 0, gcd = 0, lcm = 0;

    printf("Iveskite tris sveikuosius skaicius.\n");

    while(scanf("%lld %lld %lld", &a, &b, &c) != 3 || getchar() != '\n')
    {
        printf("Neteisingi duomenys, iveskite tris sveikus skaicius: \n");
        while(getchar() != '\n')
        {
            ;
        }
    }

    for(int i = 1; i <= a && i <= b && i <= c; i++)
    {
        if(a % i == 0 && b % i == 0 && c % i == 0)
            gcd = i;
    }

    if(gcd == 1)
        lcm = (a * b * c) / (2 * gcd);

    else lcm = (a * b * c) / (gcd * gcd);

    printf("Didiziausias bendras daliklis yra: %lld\n", gcd);

    printf("Maziausias bendras kartotinis yra : %lld\n", lcm);

    return 0;
}