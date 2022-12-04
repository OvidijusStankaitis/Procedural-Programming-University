#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int length(char s[]);
char* copy(char s[], int n);

int main()
{
    char s1[] = "Labas";
    char s2[] = " ";

    if(strcmp(copy(s1, 5), "Labas") != 0)
    {
        assert(0);
    }

    if(strcmp(copy(s1, 1), "L") != 0)
    {
        assert(0);
    }
    
    if(strcmp(copy(s2, 1), " ") != 0)
    {
        assert(0);
    }
}

int length(char s[]) 
{
    int l = 0;

    while(s[l] != '\0') {
        l++;
    }

    return l;
}

char* copy(char s[], int n)
{
    char* str = malloc(sizeof(char) * (n + 1));

    for(int i = 0; i < n; ++i) 
    {
        str[i] = s[i];
    }

    return str;
}