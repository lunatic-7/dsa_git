#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversing linked list.

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    // printf("%d ", ptr->data);
    // ptr = ptr->next;

    // while (ptr != head)
    // {
    //     printf("%d ", ptr->data);
    //     ptr = ptr->next;
    // }

    // Better way to write upper code.

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

// Inserting at the beginning and making it head.
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last element of circular linked list.

    p->next = ptr;
    ptr->next = head;
    head = ptr;

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
    head->data = 7;
    head->next = second;

    // Link second and third nodes.
    second->data = 12;
    second->next = third;

    // Link third and fourth nodes.
    third->data = 70;
    third->next = fourth;

    // Link fourth and head.
    fourth->data = 159;
    fourth->next = head;

    linkedListTraversal(head);
    head = insertAtFirst(head, 17);
    head = insertAtFirst(head, 170);
    linkedListTraversal(head);
    return 0;
}