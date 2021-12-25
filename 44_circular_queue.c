#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularqueue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularqueue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Your queue is full!\n");
    }

    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = val;
        printf("Enquing element %d\n", val);
    }
}

int dequeue(struct circularqueue *ptr)
{
    int a = -1;  // Simply denotes a wrong dequeued index.
    if (isEmpty(ptr))
    {
        printf("Your queue is Empty!\n");
    }

    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

void firstVal(struct circularqueue *ptr)
{
    printf("First value in this queue is: %d\n", ptr->arr[ptr->f+1]);
}

void lastVal(struct circularqueue *ptr)
{
    printf("Last value in this queue is: %d\n", ptr->arr[ptr->r]);
}

int peek(struct circularqueue *ptr, int index)
{
    if (index <= ptr->size - 1)
    {
        return ptr->arr[index];
    }
    else
    {
        return -1; // represents invalid index.
    }
    
}

int main()
{
    struct circularqueue qu;
    qu.size = 4;
    qu.f = qu.r = 0;
    qu.arr = (int *)malloc(qu.size * sizeof(int));    

    enqueue(&qu, 7);
    enqueue(&qu, 17);
    enqueue(&qu, 77);
    enqueue(&qu, 23);
   
    printf("Your dequeued element is: %d\n", dequeue(&qu));      

    firstVal(&qu);
    lastVal(&qu);
    printf("The value at index is: %d", peek(&qu, 4));
    return 0;
}