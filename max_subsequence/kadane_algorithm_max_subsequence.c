#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getMax(int *A, int n, int *index)
{
    int max = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
            (*index) = i;
        }
    }
    return max;
}

int kadane(int *A, int n, int *index1, int *index2)
{
    int max_sum = 0, max_current = 0;
    int reinit = 0;

    for(int i = 0; i < n; i++)
    {
        max_current = max_current + A[i];

        if(max_current < 0)
        {
            max_current = 0;
            reinit = 0;
        }
        else if(!reinit)
        {
            reinit = 1;
            (*index1) = i;
        }
        
        if(max_current > max_sum)
        {
            max_sum = max_current;
            (*index2) = i;
        }
    }

    if(max_sum == 0)
    {
        int index;
        max_sum = getMax(A, n, &index);
        
        (*index1) = index;
        (*index2) = index;
        return max_sum;
    }
    else
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
        int max_sum = kadane(A, n, &index1, &index2);
        printf("The maximum subsequence has a sum of %d and ranges from element %d to %d", max_sum, index1+1, index2+1);
        printf("\n\n");

        free(A);
    };
    return 0;
}