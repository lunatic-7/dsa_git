#include <stdio.h>
#include <limits.h> // For using INT_MIN and INT_MAX
#include <stdlib.h>

// Values of INT_MAX and INT_MIN may vary
// from compiler to compiler. Following are
// typical values in a compiler where integers
// are stored using 32 bits.

// Value of INT_MAX is +2147483647.
// Value of INT_MIN is -2147483648.

void arrTrav(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to find maximum no. in an array
int maximum(int *A, int size)
{
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int size)
{
    int i, j;

    // Find the maximum element in A
    int max = maximum(A, size);

    // Create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // We can also use calloc and skip the following part of initializing all the values with 0,
    // bc calloc itself initializes all the value with 0, whereas malloc initializes with garbage value.

    // Initialize the count array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < size; i++)
    {
        count[A[i]] = count[A[i]] + 1; // Can be written as count[A[i]]++
    }

    i = 0; // Counter for count array
    j = 0; // Counter for given array

    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {8, 0, 7, 1, 3, 9, 2, 99, 7};

    int size = sizeof(A) / sizeof(int);

    arrTrav(A, size);
    countSort(A, size);
    arrTrav(A, size);
    return 0;
}