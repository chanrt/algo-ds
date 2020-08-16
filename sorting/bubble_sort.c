#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int *bubble_sort(int *A, int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (A[j-1] > A[j])
                swap(&A[j-1], &A[j]);
        }
    }
    return A;
}

int main()
{
    while (1)
    {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);

        int *A = (int *)malloc(n*sizeof(int));

        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);

        bubble_sort(A, n);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}