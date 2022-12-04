#include <stdio.h>
#include <assert.h>

int length(char s[]);

int main()
{
    char s[] = "Labas";

    if(length(s) != 5) 
    {
        assert(0);
    }

    return 0;
}

int length(char s[]) 
{
    int l = 0;

    while(s[l] != '\0') {
        l++;
    }

    return l;
}