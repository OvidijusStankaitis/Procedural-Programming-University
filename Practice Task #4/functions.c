#include <functions.h>
#include <stdlib.h>
#include <stdbool.h>

FILE* fileValidation(FILE* file, char* mode)
{    
    char fileName[256];
    char fileNoExtName[254];

    printf("The program will open an input .txt file with the name you provided.\n");
    printf("File must exist.\n\n");
    scanf("%s", fileNoExtName);

    snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

    file = fopen(fileName, mode);

    while(file == NULL)
    {
        printf("File not found. Enter an input file name without extension:\n\n");
        printf("The program will open an input .txt file with the name you provided.\n");
        printf("File must exist.\n\n");
        scanf("%s", fileNoExtName);
    
        snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

        file = fopen(fileName, mode);
    }

    return file;
}

int Validation(FILE* in, bool* status)
{
    int n;
    int loop = 0;
    char c;

    while(!loop)
    {
        if(fscanf(in, "%d", &n) == 1) 
        {   
            c = fgetc(in);
            if(c == ' ' || c == '\n' || c == EOF) 
            {
                return n;
            }
        }

        if(fgetc(in) == EOF)
        {
            loop = 1;
            *status = false;
        }
    }

    return n;
}

int choiceValidation(int n)
{
    while(scanf("%d", &n) != 1 || getchar() != '\n')
    {
        printf("\nThis option does not exist!\n\n");
        printf("1.Create the linked list from an input file\n");
        printf("2.Print out the linked list\n");
        printf("3.Remove the largest number from the list\n");
        printf("4.Exit program\n\n");
        while(getchar() != '\n')
        {
            ;
        }
    }

    return n;
}

void menu(Node** head, FILE* in, bool* menuS)
{
    int choice = 0;

    int MAX = 0;

    printf("1.Create the linked list from an input file\n");
    printf("2.Print out the linked list\n");
    printf("3.Remove the largest number from the list\n");
    printf("4.Exit program\n\n");

    printf("Enter your choice:\n\n");
    choice = choiceValidation(choice);
    printf("\n");

    switch(choice)
    {
        case 1:
            printf("List was created.\n\n");
            createList(head, in);
            break;
            
        case 2:
            printf("List: ");
            printList(head);
            printf("\n\n");
            break;

        case 3:
            if((*head) == NULL)
            {
                printf("List is empty\n\n");
            }

            else
            {
                MAX = findMax(head);
                removeMax(MAX, head);
            }
            break;

        case 4: 
            *menuS = false;
            break;
        
        default:
            printf("This option does not exist!\n\n");
            break;
    }
}

void createList(Node** head, FILE* in)
{
    Node* temp;
    Node* ptr;

    bool status = true;

    int n;

    while(!feof(in))
    {
        n = Validation(in, &status);

        temp = (Node*)malloc(sizeof(Node));

        if(temp == NULL)
        {
            printf("Out of memory!\n");
            _Exit(0);
        }

        temp -> data = n;

        temp -> next = NULL;

        if((*head) == NULL)
        {
            (*head) = temp;
        }

        else
        {
            ptr = (*head);

            while(ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = temp;
        }        
    }
}

void printList(Node** head)
{
    Node* ptr;

    if((*head) == NULL)
    {
        printf("List is empty");
        return;
    }

    else
    {    
        printf("%d ", (*head) -> data);
        if((*head) -> next == NULL)
        {
            return;
        }
        
        ptr = (*head) -> next;
        printList(&ptr);
    }
}

int findMax(Node** head)
{    
    int MAX = (*head) -> data;
    Node* ptr;

    ptr = (*head) -> next;

    while(ptr != NULL) 
    {
        if(MAX < ptr -> data)
        {
            MAX = ptr -> data;
        }
        ptr = ptr -> next;
    }

    return MAX;
}

void removeMax(int MAX, Node** head)
{
    Node* temp = (*head);
    Node* previous;

    if(temp != NULL && temp -> data == MAX)
    {
        (*head) = temp -> next;
        free(temp);
    }

    temp = (*head);

    previous = temp;

    while(temp != NULL)
    {
        if(temp -> data != MAX)
        {
            previous = temp;
            temp = temp -> next;
        }

        else
        {
            previous -> next = temp -> next;
            free(temp);
            temp = previous -> next;

            if((*head) -> next == NULL)
            {
                (*head) = NULL;
            }
        }
    }
}