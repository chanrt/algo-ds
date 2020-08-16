#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_subsequence_naive(int *A, int n, int *index1, int *index2)
{
    int sum, max_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
                sum = sum + A[k];

            if (sum > max_sum)
            {
                max_sum = sum;
                (*index1) = i;
                (*index2) = j;
            }
        }
    }
    return max_sum;
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

        int index1, index2;
        int max_sum = max_subsequence_naive(A, n, &index1, &index2);
        printf("The maximum subsequence has a sum of %d and ranges from element %d to %d", max_sum, index1+1, index2+1);
        printf("\n\n");

        free(A);
    };
    return 0;
}