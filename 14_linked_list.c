#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversing linked list.

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
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

    // Link first and second nodes.
    head -> data = 7;
    head -> next = second;
    
    // Link second and third nodes.
    second -> data = 12;
    second -> next = third;
    
    // Link third and fourth nodes.
    third -> data = 70;
    third -> next = fourth;
    
    // Terminate the list at the fourth node.
    fourth -> data = 159;
    fourth -> next = NULL;

    linkedListTraversal(head);
    return 0;
}