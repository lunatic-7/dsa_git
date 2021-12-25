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
    printf("\n");
    
}

// Deleting the first Node.
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    
    return head;
}

// Deleting in between
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head;

    int i = 0;
    int j = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    
    while (j != index)
    {
        q = q->next;
        j++;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Delete at end
struct Node *deleteAtEnd(struct Node *head)
{

    
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    int j = 0;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    
    p->next = NULL;
    free(q);
    return head;
}

// Deleting the element with a given value from the linked list
struct Node *deleteByValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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
    
    head = deleteAtFirst(head);
    linkedListTraversal(head);

    head = deleteAtIndex(head, 2);
    linkedListTraversal(head);
   
    head = deleteAtEnd(head);
    linkedListTraversal(head);
    
    head = deleteByValue(head, 12);
    linkedListTraversal(head);

    return 0;
}