#include <functions.h>

int main()
{
    FILE* in = NULL;
    
    printf("Enter an input file name wihout extension:\n");
    in = fileValidation(in, "r");
    printf("\n");

    Node* head = NULL;

    while(1)
    {
        menu(&head, in);
    }

    return 0;
}