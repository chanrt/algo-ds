#include <stdio.h>
#include <stdlib.h>

int *insertion_sort_recursive(int *A, int n, int index)
{
    if (index == n) return A;

    int key = A[index];
    int i = index - 1;

    while (i > -1 && A[i] > key)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = key;

    return insertion_sort_recursive(A, n, index+1);
}

int main()
{
    while (1)
    {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);

        if (n < 2)
        {
            printf("That's a trivial case\n");
            continue;
        }

        int *A = (int *)malloc(n*sizeof(int));

        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);

        insertion_sort_recursive(A, n, 1);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}