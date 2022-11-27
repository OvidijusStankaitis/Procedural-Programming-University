#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;
}Point;

typedef struct Stack
{
    Point* data;
    int size;
} Stack;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);
void initStack(Stack* stack);
void printStack(Stack* stack);
void push(Stack* stack, Point value);
void destroyStack(Stack* stack);

int main()
{
    Stack* stack = malloc(sizeof(Stack*));

    initStack(stack);

    push(stack, createPoint(48.12, 83.56));
    push(stack, createPoint(79.69, 76.29));
    push(stack, createPoint(28.61, 81.44));
    push(stack, createPoint(6.32, 55.6));
    push(stack, createPoint(58.74, 83.66));
    
    printStack(stack);

    destroyStack(stack);

    return 0;
}

void printPoint(Point p)
{
    printf("(%.2f; %.2f)", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    double l = sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
    return l;
}

void initStack(Stack* stack)
{
    stack -> size = 0;
    stack -> data = NULL;
}

void printStack(Stack* stack)
{
    if(stack -> data != NULL)
    {
        for(int i = 0; i < stack -> size; i++)
        {
            printf("Distance - ");
            printPoint(stack->data[i]);
            printf(" to the origin of the graph - %.2lf\n\n", getDistance(createPoint(0, 0), stack -> data[i]));
        }
    }
}

void push(Stack* stack, Point value)
{
    if(stack -> size == 0)
    {
        stack -> data = malloc(sizeof(stack -> data));
        stack -> data[0] = value;
        stack -> size++;
    }

    else
    {
        stack -> data = realloc(stack -> data, (stack -> size + 1) * sizeof(Point));
        stack -> data[stack -> size] = value;
        stack -> size++;
    }
}

void destroyStack(Stack *stack)
{
    free(stack -> data);
    stack -> size = 0;
}