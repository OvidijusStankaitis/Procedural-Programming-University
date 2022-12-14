#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

FILE* fileValidation(FILE* file, char* mode);

int Validation(FILE* in, bool* status);

int choiceValidation(int n);

void menu(Node** head, FILE* in);

void createList(Node** head, FILE* in);

void printList(Node** head);