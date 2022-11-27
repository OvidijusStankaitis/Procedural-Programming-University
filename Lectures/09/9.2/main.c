#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int* pointer;
    int size;
} Stack;

void initStack(Stack* stack);
void printStack(Stack* stack);
int getStackSize(Stack* stack);
void push(Stack* stack, int value);
int top(Stack* stack);
int pop(Stack* stack);
int destroyStack(Stack* stack);

int main()
{
    Stack* stack = malloc(sizeof(Stack*));
    
    initStack(stack);
    push(stack, 20);
    printStack(stack);
    push(stack, 100);
    printf("Stack size: %d\n\n", getStackSize(stack));
    printf("Stack top: %d\n\n", top(stack));
    push(stack, 11111);
    printf("Stack pop: %d\n\n", pop(stack));
    printStack(stack);
    destroyStack(stack);

    return 0;
}

void initStack(Stack* stack)
{
    stack -> size = 0;
    stack -> pointer = NULL;
}

void printStack(Stack* stack)
{
    if(stack -> pointer != NULL)
    {
        for(int i = 0; i < stack -> size; i++)
        {
            printf("Index - %d\nValue - %d\n\n", i, stack -> pointer[i]);
        }        
    }
}

int getStackSize(Stack* stack)
{
    return stack -> size;
}

void push(Stack* stack, int value)
{
    if(stack -> size == 0)
    {
        stack -> pointer = malloc(sizeof(stack -> pointer));
        stack -> pointer[0] = value;
        stack -> size++;
    }

    else
    {
        stack -> pointer = realloc(stack -> pointer, stack -> size + 1);
        stack -> pointer[stack -> size] = value;
        stack -> size++;
    }
}

int top(Stack* stack)
{
    if (stack -> pointer == NULL)
        return 0;
    else
        return stack -> pointer[stack -> size-1];
}

int pop(Stack* stack)
{
    int TOP = top(stack);
    stack -> pointer = realloc(stack -> pointer, stack -> size-1);
    stack -> size--;
    return TOP;
}

int destroyStack(Stack* stack)
{
    free(stack -> pointer);
    stack -> size = 0;
}