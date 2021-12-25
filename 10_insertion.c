#include <stdio.h>

void display(int arr[], int n)
{
    //code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

int indInsertion(int arr[] , int size, int element, int capacity, int index)
{
    // code for insertion
    if (size >= capacity)
    {
         return -1;
    }
    else
    {
        for (int i = size-1; i <= index ; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
    
}

int main()
{
    int arr[100] = {12, 3, 233, 7, 43};
    int size = 5, element = 77, index = 3;
    display(arr, size);

    indInsertion(arr , size, element, 100, index);
    size += 1;
    display(arr, size);

    return 0;
}