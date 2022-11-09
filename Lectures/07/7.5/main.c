#include <stdio.h>

long int getFileSize(char fileName[]);

int main()
{
    char fileName[65535] = {' '};
    
    printf("Iveskite failo, kurio dydi norite suzinoti pavadinima: \n");

    scanf("%s", fileName);

    long long int num = getFileSize(fileName);

    if(num == -1)
    {
        printf("Tokio failo nera");
    }

    else printf("\nFailo dydis yra %lld bytes\n", num);

    return 0;
}

long int getFileSize(char fileName[])
{
    FILE* file = fopen(fileName, "r");
  
    if (file == NULL) 
    {
        return -1;
    }
  
    fseek(file, 0L, SEEK_END);
  
    long int res = ftell(file);
  
    fclose(file);
  
    return res;
}