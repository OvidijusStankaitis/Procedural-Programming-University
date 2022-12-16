// LSP numeris 2213794
// ovidijus.stankaitis@mif.stud.vu.lt
// Užduoties nr. - 4
// Variantas nr. - 7

#include <functions.h>
#include <stdbool.h>

int main()
{
    FILE* in = NULL;
    
    printf("Enter an input file name wihout extension:\n");
    in = fileValidation(in, "r");
    printf("\n");

    Node* head = NULL;

    bool menuS = true;

    while(menuS)
    {
        menu(&head, in, &menuS);
    }

    fclose(in);

    return 0;
}