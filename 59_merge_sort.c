#include <stdio.h>

void arrTrav(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void ms(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        ms(A, low, mid);
        ms(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {8, 0, 7, 1, 3};
    int A[] = {9, 1, 4, 14, 4, 15, 6};

    int size = sizeof(A) / sizeof(int);

    arrTrav(A, size);
    ms(A, 0, size - 1);
    arrTrav(A, size);
    return 0;
}