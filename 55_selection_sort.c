#include <stdio.h>

void arrTrav(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int size)
{
    int temp;
    int indexOfMin;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    int A[] = {8, 0, 7, 1, 3};

    int size = sizeof(A) / sizeof(int);

    arrTrav(A, size);
    selectionSort(A, size);
    arrTrav(A, size);
    return 0;
}