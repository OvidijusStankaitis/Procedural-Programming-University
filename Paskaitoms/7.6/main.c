#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int showMenu(int menuSize, char *menuTitle, char menuOptions[menuSize][MAX], char *inputMsg);

int main() 
{

    char title[] = "Visual Studio Code";
    char options[][MAX] = {"File", "Edit", "Selection", "View", "Go", "Run"};

    int size = sizeof(options)/sizeof(options[0]);

    char message[] = "If you wish to choose an option, enter the number of the option: ";
    int choice;

    choice = showMenu(size, title, options, message);
    printf("\nYou chose option number %d - %s\n", choice, options[choice - 1]);

    return 0;
}

int showMenu(int menuSize, char *menuTitle, char menuOptions[menuSize][MAX], char *inputMsg) 
{
    int num;
    bool invalidInput = true;
    
    printf("%s:\n\n", menuTitle);

    for (int i = 0; i < menuSize; i++) 
    {
        printf("%5d. %s\n", i + 1, menuOptions[i]);
    }

    printf("\n\n%s\n\n", inputMsg);

    while(scanf("%d", &num) != 1 || num < 0 || num > menuSize || getchar() != '\n')
    {
        printf("\n%s\n\n", inputMsg);
        while(getchar() != '\n')
        {
            ;
        }
    }

    return  num;
}