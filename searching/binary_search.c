#include <stdio.h>
#include <stdlib.h>

int *insertion_sort(int *A, int n)
{
    int key, index;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        index = i - 1;

        while (index > -1 && A[index] > key)
        {
            A[index+1] = A[index];
            index--;
        }

        A[index+1] = key;
    }
    return A;
}

int binary_search(int *A, int left, int right, int num)
{
    if (left == right)
    {
        if(A[left] == num) 
            return left;
        else 
            return -1;
    }

    int mid = (left + right) / 2;

    if (A[mid] == num) return mid;
    else if (A[mid] < num) return binary_search(A, mid+1, right, num);
    else return binary_search(A, left, mid-1, num);
}

int main()
{
    while (1)
    {
        int size;
        printf("Enter size: ");
        scanf("%d", &size);

        int *A = (int *)malloc(size*sizeof(int));

        printf("Enter elements: ");
        for (int i = 0; i < size; i++) scanf("%d", &A[i]);

        int num;
        printf("Enter number to search: ");
        scanf("%d", &num);

        insertion_sort(A, size);

        int index = binary_search(A, 0, size-1, num);
        if (index == -1)
            printf("Number %d not found", num);

        else
            printf("Number exists at position %d in the sorted list", index+1);

        printf("\n\n");
        free(A);
    };
    return 0;
}