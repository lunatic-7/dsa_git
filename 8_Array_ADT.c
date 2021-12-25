#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    
    // Short-cut of writing above code: 
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));  // Reserving memory.
}

void setValue(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)  //  Using necessary memory and setting value from reserved memory.
    {
        printf("Enter the value of Element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
    
}


int main()
{
    struct myArray marks;
    createArray(&marks, 10, 7);
    printf("We are running setValue now: \n");
    setValue(&marks);

    printf("We are running show now: \n");
    show(&marks);
    
    return 0;
}