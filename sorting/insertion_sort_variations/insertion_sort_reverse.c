#include <stdio.h>
#include <stdlib.h>

// reversing one sign is enough!
int *insertion_sort_reverse(int *A, int n)
{
    int key, index;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        index = i - 1;

        while (index > -1 && A[index] < key)
        {
            A[index+1] = A[index];
            index--;
        }

        A[index+1] = key;
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

        insertion_sort_reverse(A, n);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}