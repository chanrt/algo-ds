#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int *A, int left, int right)
{
    swap(&A[(rand() % right) + left], &A[right]);

    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (A[j] <= A[right])
            swap(&A[++i], &A[j]);
    }
    swap(&A[i+1], &A[right]);

    return (i+1);
}

void quick_sort(int *A, int left, int right)
{
    if (left < right)
    {
        int mid = partition(A, left, right);
        quick_sort(A, left, mid-1);
        quick_sort(A, mid+1, right);
    }
    else return;
}

int main()
{
    srand(time(NULL));
    while (1)
    {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);

        int *A = (int *)malloc(n*sizeof(int));

        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);

        quick_sort(A, 0, n-1);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}