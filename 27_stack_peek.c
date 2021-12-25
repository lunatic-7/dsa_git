#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// Check if stack is empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check if stack is full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Your value %d can't be added.\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Nothing to be popped!.\n");
        return -1;
    }
    else
    {
        int var = ptr->arr[ptr->top];
        ptr->top--;
        return var;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for stack!");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 17);
    push(sp, 137);
    push(sp, 7);
    push(sp, 34);
    push(sp, 82);
    push(sp, 1);
    push(sp, 1);
    push(sp, 0);
    push(sp, 93);
    push(sp, 14); // Pushed 10 values
    push(sp, 27); // Stack overflow since the size of stack is 10.

    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    printf("The value of topmost element in our stack is: %d\n", stackTop(sp));
    printf("The value of bottomost element in our stack is: %d\n", stackBottom(sp));
    
    return 0;
}