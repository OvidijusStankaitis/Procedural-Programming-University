#include <functions.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

FILE* fileValidation(FILE* file, char* mode)
{    
    char fileName[256];
    char fileNoExtName[254];

    // Prompts user for input
    printf("The program will open an input .txt file with the name you provided.\n");
    printf("File must exist.\n\n");
    scanf("%s", fileNoExtName);

    snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

    file = fopen(fileName, mode);

    // Tells user that file was not found, propmpts for input again
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

int validationData(FILE* in, bool* status)
{
    int n = 77;
    bool loop = true;
    char c, prev = '1';

    while(loop)
    {
        c = fgetc(in);      
        if(isdigit(c))
        {
            fseek(in, -1, SEEK_CUR);

            if(fscanf(in, "%d", &n) == 1 && isdigit(prev)) 
            {   
                c = fgetc(in);
                if(c == ' ' || c == '\n' || c == EOF) 
                {
                    return n;
                }
            }
        }

        else 
        {
            if(c == ' ' || c == '\n')
                prev = '1';
            
            else
                prev = '!';
        }

        if(c == EOF)
        {
            loop = false;
            *status = false;
        }
    }

    return n;
}

int choiceValidation(int n)
{
    // When user choice is littered with symbols and letters
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

    // Loops while encounters eof
    while(!feof(in))
    {
        n = validationData(in, &status);

        temp = (Node*)malloc(sizeof(Node));
        
        // Prints prompt if no more memory exists
        if(temp == NULL)
        {
            printf("Out of memory!\n");
            _Exit(0);
        }
        
        // Puts data inside the list after it passes validation and while not eof
        if(status)
        {
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

    // Puts cursor to the begining of file
    fseek(in, 0, SEEK_SET);
}

void printList(Node** head)
{
    Node* ptr;

    // If list is empty
    if((*head) == NULL)
    {
        printf("List is empty");
        return;
    }

    // Prints the elemt of the list and uses recursrion to print the next element
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

    // Loops through the list and finds the MAX
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

    // If the max value is in head
    while(temp != NULL && temp -> data == MAX)
    {
        (*head) = temp -> next;
        free(temp);
        temp = (*head);
    }

    previous = temp;

    // Checks the rest of the list for the max value
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