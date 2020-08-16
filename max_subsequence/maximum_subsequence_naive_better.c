#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_subsequence_better(int *A, int n, int *index1, int *index2)
{
    int sum, max_sum = INT_MIN;

    // loop over length of the sub-arrrys
    for (int i = 1; i < n+1; i++)
    {
        sum = 0;

        // taking sliding each sub-array of size i throughtout the array
        for (int j = 0; j < n; j++)
        {
            // until size i is not reached
            if (j < i) sum = sum + A[j];
            // subtract the first element and the next element
            else sum = sum - A[j-i] + A[j];

            // check if current sum is greater than previous greatest sum
            if (sum > max_sum)
            {
                max_sum = sum;
                (*index1) = j-i+1;
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
        int max_sum = max_subsequence_better(A, n, &index1, &index2);
        printf("The maximum subsequence has a sum of %d and ranges from element %d to %d", max_sum, index1+1, index2+1);
        printf("\n\n");

        free(A);
    };
    return 0;
}