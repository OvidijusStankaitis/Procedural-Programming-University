#include <stdio.h>
#include <assert.h>

int length(char s[]);
int compare(char* s1, char* s2);

int main()
{
    char s1[] = "ABC", s2[] = "abc", s3[] = "ABCD";

    if(compare(s1, s2) != -1) 
    {
        assert(0);
    }

    else if(compare(s1, s3) != -1) 
    {
        assert(0);
    }

    else if(compare(s1, s1) != 0) 
    {
        assert(0);
    }

    else if(compare(s2, s1) != 1) 
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

int compare(char* s1, char* s2)
{
    int l1 = length(s1);
    int l2 = length(s2);

    if(l1 > l2)
    {
        return 1;
    }

    else if (l1 < l2)
    {
        return -1;
    }

    for(int i = 0; i < l1; ++i) 
    {
        if(s1[i] > s2[i])
        {
            return 1;
        }

        else if(s1[i] < s2[i])
        {
            return -1;
        }
    }

    return 0;
}
