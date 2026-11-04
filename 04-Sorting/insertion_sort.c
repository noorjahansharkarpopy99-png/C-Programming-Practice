
#include <stdio.h>

void insertion_sort(int A[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    insertion_sort(A, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}
