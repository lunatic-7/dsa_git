#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *p)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int x)
{
    if (isFull(r))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
            printf("Enqueing element: %d\n", x);
        }
        else
        {
            r->next = n;
            r = n;
            printf("Enqueing element: %d\n", x);
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *ptr = f;

    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        f = f->next;
        x = ptr->data;
        free(ptr);
    }
    return x;
}

int peek(int pos)
{
    struct Node *ptr = f;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    printf("Dequeing Element: %d\n", dequeue());
    enqueue(17);
    enqueue(15);
    enqueue(12);
    enqueue(7);

    printf("Dequeing Element: %d\n", dequeue());
    printf("Dequeing Element: %d\n", dequeue());

    linkedListTraversal(f);

    printf("The value at position 1 is: %d\n", peek(1));

    return 0;
}
