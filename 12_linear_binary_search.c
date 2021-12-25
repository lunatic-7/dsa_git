#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
        
    }
    return -1;
    
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    // Start Searching...
    while (low <= high)
    {
        mid = (low + high)/2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Search Ends.
    
}

int main()
{
    int arrL[] = {1,2,3,27,4,55,6,7,654}; // Unsorted array for linear search.
    int elementL = 7;
    int sizeL = sizeof(arrL)/ sizeof(int); // Trick to find array size, without manually counting.
    int searchIndexL = linearSearch(arrL, sizeL, elementL);
    printf("The element: %d is found at index: %d\n\n", elementL, searchIndexL);
    
    int arrB[] = {1,2,3,27,44,55,61,77,654,1023}; // Sorted array for binary search.
    int elementB = 77;
    int sizeB = sizeof(arrB)/ sizeof(int); // Trick to find array size, without manually counting.
    int searchIndexB = linearSearch(arrB, sizeB, elementB);
    printf("The element: %d is found at index: %d", elementB, searchIndexB);

    return 0;
}