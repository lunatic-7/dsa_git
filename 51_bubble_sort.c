#include <stdio.h>

void aTrav(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Modified bubble sort
void bubbleSortAdaptive(int *A, int size)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++) // for number of pass.
    {
        printf("Working on pass no. : %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < (size - 1 - i); j++) // for comparison in each pass.
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int bubbleSort(int *A, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) // for number of pass.
    {
        for (int j = 0; j < (size - 1 - i); j++) // for comparison in each pass.
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {12, 3, 4, 5, 56, 213, 432, 21, 3, 0};
    // int A[] = {1, 3, 4, 5, 56, 233, 433, 621, 773, 880};

    int size = sizeof(A) / sizeof(int);

    aTrav(A, size); // Before sorting
    bubbleSortAdaptive(A, size);
    bubbleSort(A, size);
    aTrav(A, size); // After sorting

    return 0;
}