#include <stdio.h>
#include <stdlib.h>

int inversion_naive(int *A, int n)
{
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                printf("[%d, %d]\n", A[i], A[j]);
                num++;
            }
        }
    }
    return num;
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

        printf("Number of inversions: %d", inversion_naive(A, n));
        printf("\n\n");
        free(A);
    };
    return 0;
}