#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Traversing linked list forward.

void linkedListTraversalF(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
}

// Traversing linked list backward.

void linkedListTraversalB(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocating memory for the nodes in linked list in heap.
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    head -> data = 7;
    head -> next = second;
    head -> prev = NULL;
    

    second -> data = 12;
    second -> next = third;
    second -> prev = head;
    

    third -> data = 70;
    third -> next = fourth;
    third -> prev = second;
    

    fourth -> data = 159;
    fourth -> next = NULL;
    fourth -> prev = third;

    linkedListTraversalF(head);
    printf("\n");
    linkedListTraversalB(fourth);
    return 0;
}