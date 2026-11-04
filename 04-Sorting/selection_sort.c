
#include <stdio.h>

void selection_sort(int A[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main()
{
    int A[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    selection_sort(A, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}
