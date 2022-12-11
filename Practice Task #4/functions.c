#include <stdio.h>

FILE* fileValidation(FILE* file, char* mode)
{    
    char fileName[256];
    char fileNoExtName[254];

    printf("The program will open a .txt file with the name you provided.\n");
    printf("Input file must exist, output file will be created.\n");
    scanf("%s", fileNoExtName);

    snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

    file = fopen(fileName, mode);

    while(file == NULL)
    {
        printf("File not found. Please enter a file name without extension:\n\n");
        printf("The program will open a .txt file with the name you provided.\n");
        printf("Input file must exist, output file will be created.\n");
        scanf("%s", fileNoExtName);
    
        snprintf(fileName, sizeof(fileName), "%s.txt", fileNoExtName);

        file = fopen(fileName, mode);
    }

    return file;
}

void menu()
{
    int choice = 0;

    printf("1.Print out the linked list\n");
    printf("2.Remove the largest number from the list\n");
    printf("3.Exit program\n");

    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            break;
            
        case 2:
            break;

        case 3: 
            _Exit(0);
        
        default:
            printf("This option does not exist\n");
            break;
    }
}