#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Iveskite 3 skaicius atskirtus tarpu\n");
    double x = 0, y = 0;
    int z = 0;

    scanf("%lf %lf %d", &x, &y, &z);

    double A, B;

    A = x + 4 * y + pow(z, 3);
    B = (x + sqrt(y))*(pow(z, 4) - abs(z) + 46.3);

    printf("%f %f \n", A, B);

    return 0;
}
