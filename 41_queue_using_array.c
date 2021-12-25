#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *ptr)
{
    if (ptr->r == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Your queue is full!\n");
    }

    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct queue *ptr)
{
    int a = -1;  // Simply denotes a wrong dequeued index.
    if (isEmpty(ptr))
    {
        printf("Your queue is Empty!\n");
    }

    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

void firstVal(struct queue *ptr)
{
    printf("First value in this queue is: %d\n", ptr->arr[ptr->f+1]);
}

void lastVal(struct queue *ptr)
{
    printf("Last value in this queue is: %d\n", ptr->arr[ptr->r]);
}

int peek(struct queue *ptr, int index)
{
    if (index <= ptr->size - 1)
    {
        return ptr->arr[index];
    }
    else
    {
        printf("Enter a Valid Index!");
    }
    
}

int main()
{
    struct queue qu;
    qu.size = 20;
    qu.f = qu.r = -1;
    qu.arr = (int *)malloc(qu.size * sizeof(int));    

    enqueue(&qu, 7);
    enqueue(&qu, 17);
    enqueue(&qu, 77);
    enqueue(&qu, 23);
   
    printf("Your dequeued element is: %d\n", dequeue(&qu));      

    firstVal(&qu);
    lastVal(&qu);
    printf("The value at index is: %d", peek(&qu, 2));
    return 0;
}