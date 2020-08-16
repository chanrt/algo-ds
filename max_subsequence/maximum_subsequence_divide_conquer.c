#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_subsequence_mid(int *A, int left, int mid, int right, int *index1, int *index2)
{
    int sum, left_sum = INT_MIN, right_sum = INT_MIN;

    sum = 0;
    for (int i = mid; i >= left; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            (*index1) = i;
        }
    }

    sum = 0;
    for (int j = mid+1; j <= right; j++)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            (*index2) = j;
        }
    }
    return (left_sum + right_sum);
}

int max_subsequence(int *A, int left, int right, int *index1, int *index2)
{
    if (left == right)
    {
        (*index1) = left;
        (*index2) = right;
        return A[left];
    }

    else
    {
        int mid = (left + right) / 2;
        int left1, left2, right1, right2, mid1, mid2;

        int sum_left = max_subsequence(A, left, mid, &left1, &left2);
        int sum_right = max_subsequence(A, mid+1, right, &right1, &right2);
        int sum_mid = max_subsequence_mid(A, left, mid, right, &mid1, &mid2);

        if (sum_left > sum_right && sum_left > sum_mid)
        {
            (*index1) = left1;
            (*index2) = left2;
            return sum_left;
        }
        else if (sum_right > sum_left && sum_right > sum_mid)
        {
            (*index1) = right1;
            (*index2) = right2;
            return sum_right;
        }
        else
        {
            (*index1) = mid1;
            (*index2) = mid2;
            return sum_mid;
        }
    }
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
        int max_sum = max_subsequence(A, 0, n-1, &index1, &index2);
        printf("The maxium subsequence has a sum of %d and ranges from %d to %d", max_sum, index1+1, index2+2);
        printf("\n\n");

        free(A);
    };
    return 0;
}