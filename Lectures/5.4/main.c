#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int* buffer;
    size_t buffer_size = 1000;

    buffer = malloc(sizeof(int) * buffer_size);

    size_t n = 0;
    int x = 0;

    printf("Programa leidzia vesti teigiamus sveikus skaicius ir atspausdina visus ivestus pirminius skaicius nesikartojant.\n");
    printf("Vedimas baigiasi ivedus reiksme mazesne uz 0.\n\n");

    printf("Veskite teigiamus sveikus skaicius. Vedima uzbaikite ivesdami neigiama reiksme.\n");

    while (true)
    {
        scanf("%d", &x);
        if (x < 0) break;

        buffer[n] = x;

        n++;
        if (n >= buffer_size)
        {

            buffer_size += 1000;
            buffer = realloc(buffer, buffer_size * sizeof(int));
        }
    }

    int X[n];
    int index = 0;

    for(int i = 0; i < n; i++)
    {
        X[i] = -1;
    }

    printf("\n");
    printf("Ivesti pirminiai skaiciai:\n");

    for(int i = 0; i < n; i++)
    {
        int c = 0;
        bool printStatus = true;

        for (int j = 1; j <= buffer[i]; j++)
        {
            if (buffer[i] % j == 0) 
            {
                c++;
            }
        }
        
        if(c == 2)
        {
            for(int j = 0; j < n; j++)
            {
                if(buffer[i] == X[j])
                {
                    printStatus = false;
                    break;
                }
            }
            
            if(printStatus == true)
            {
                printf("%d\n", buffer[i]);
                X[index] = buffer[i];
                index++;
            }
        }
    }
    
    free(buffer);

    return 0;
}