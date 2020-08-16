#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int findMax(int *A, int m, int *index)
{
    int max = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
            *index = i;
        }
    }
    return max;
}

int *selection_sort(int *A, int n)
{
    int max, index;
    for (int i = n-1; i > 0; i--)
    {
        max = findMax(A, i+1, &index);
        swap(&A[i], &A[index]);
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

        selection_sort(A, n);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}