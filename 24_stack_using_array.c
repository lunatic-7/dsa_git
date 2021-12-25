#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// Check if stack is empty
void isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("The stack is Empty.\n");
    }
    else
    {
        printf("The stack is not Empty.\n");
    }
    
}

// Check if stack is full
void isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("The stack is Full.\n");
    }
    else
    {
        printf("The stack is not Full.\n");
    }
    
}

int main()
{
    struct stack *s;

    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));

    isEmpty(s);
    isFull(s);
    return 0;
}