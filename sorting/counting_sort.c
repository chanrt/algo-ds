#include <stdio.h>
#include <stdlib.h>

int findMax(int *A, int n, int *delta)
{
    int max = INT_MIN, min = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
        if(A[i] < min)
            min = A[i];
    }
    if(min < 0)
    {
        *delta = -min;

        for(int i = 0; i < n; i++)
            A[i] += *delta;

        return (max + *delta + 1);
    }
    else return (max+1);
}

int counting_sort(int *A, int *B, int n, int max, int delta)
{
    int *C = (int *)malloc(max*sizeof(int));

    for(int i = 0; i < max; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[A[i]]++;
    
    for(int i = 1; i < max; i++)
        C[i] += C[i-1];

    for(int i = n-1; i > -1; i--)
        B[--C[A[i]]] = A[i];

    if(delta)
    {
        for(int i = 0; i < n; i++)
            B[i] -= delta;
    }

    free(C);
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

        int delta = 0, max;
        max = findMax(A, n, &delta);

        int *B = (int *)malloc(n*sizeof(int));
        
        counting_sort(A, B, n, max, delta);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", B[i]);
        printf("\n\n");

        free(A);
        free(B);
    };
    return 0;
}