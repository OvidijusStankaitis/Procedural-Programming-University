#include <stdio.h>
#include <stdlib.h>
#include <functions.h>
#include <assert.h>

int main()
{
    /*Opening file*/
    FILE* in = fopen("test.txt", "r");

    Node* head = NULL;

    /*Testing if list was created without mistakes*/
    createList(&head, in);

    int S[6] = {1, 2, 3, 4, 6, 5};
    
    Node* temp = head;

    for(int i = 0; i < 6; i++)
    {
        assert(temp -> data == S[i]);
        temp = temp -> next;
    }

    printf("Test #1 passed. List is created without mistakes.\n");

    /*Testing if the program iterated throught the whole list*/
    assert(temp == NULL);
    printf("Test #2 passed. Program iterated through the entire list.\n");

    /*Testting if the max value was found*/
    int max = findMax(&head);
    assert(max == 6);

    printf("Test #3 passed. Correct max value was found\n");

    /*Testing if the max value was removed*/
    removeMax(max, &head);

    int A[5] = {1, 2, 3, 4, 5};

    temp = head;

    for(int i = 0; i < 5; i++)
    {
        assert(temp -> data == A[i]);
        temp = temp -> next;
    }

    // assert(head == NULL);

    printf("Test #4 passed. Correct value was removed.\n");

    /*Testing if the program iterated throught the whole list*/
    assert(temp == NULL);
    printf("Test #5 passed. Program iterated through the entire list.\n");

    return 0;
}