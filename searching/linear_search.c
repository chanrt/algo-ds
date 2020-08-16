#include <stdio.h>
#include <stdlib.h>

int *linear_search(int *A, int size, int num, int *index)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] == num)
        {
            *index = i;
            return &A[i];
        }
    }
    *index = -1;
    return NULL;
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
        printf("Enter the element to be searched: ");
        scanf("%d", &num);

        int index;
        int *ptr = linear_search(A, size, num, &index);

        if (ptr != NULL)
            printf("The element %d was found at position %d", num, index+1);
        else
            printf("Element %d not found", num);
        printf("\n\n");

        free(A);
    };
    return 0;
}