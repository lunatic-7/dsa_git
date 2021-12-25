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

// Insert at the beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = head;
    return ptr;
}

// Insert at end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head;
    while (p->next !=NULL)
    {
        p = p->next;
    }
    
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Insert after node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Insert in between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
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
    printf("\n");

    head = insertAtFirst(head, 0);
    linkedListTraversal(head);
    printf("\n");

    head = insertAtIndex(head, 670, 1);
    linkedListTraversal(head);
    printf("\n");

    head = insertAtEnd(head, 89);
    linkedListTraversal(head);
    printf("\n");

    head = insertAfterNode(head, second, 10);
    linkedListTraversal(head);

    return 0;
}