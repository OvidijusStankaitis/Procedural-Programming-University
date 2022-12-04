#include <stdio.h>
#include <string.h>
#include <assert.h>

void set(char s[], char c, int n);

int main() 
{
    char s[] = "ABCDEFGHIJKLMNOPRST";

    set(s, '$', 7);

    if(strcmp(s, "$$$$$$$HIJKLMNOPRST") != 0)
    {
        assert(0);
    }

    set(s, 'X', 0);

    if(strcmp(s, "$$$$$$$HIJKLMNOPRST") != 0)
    {
        assert(0);
    }

    return 0;
}

void set(char s[], char c, int n)
{
    for(int i = 0; i < n; ++i) 
    {
        s[i] = c;
    }
}