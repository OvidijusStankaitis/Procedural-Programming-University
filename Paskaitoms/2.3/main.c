#include <stdio.h>
#include <string.h>

int main() {

    printf("Iveskite skaiciu: \n");
    int n = 0, m = 0;
    scanf("%d", &n);
    char koksSkaicius[10];

    (n % 2 == 0) ? strcpy(koksSkaicius, "lyginis") : strcpy(koksSkaicius, "nelyginis");

    printf("Skaicius %d yra %s.", n, koksSkaicius);

    return 0;
}
