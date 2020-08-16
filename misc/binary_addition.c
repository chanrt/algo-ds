#include <stdio.h>
#include <stdlib.h>

int *binary_addition(int *A, int *B, int n)
{
    int *C = (int *) malloc((n+1)*sizeof(int));
    int carry = 0, sum;

    for(int i = n - 1; i > -1; i--)
    {
        sum = A[i] + B[i] + carry;
        C[i+1] = sum % 2;
        carry = sum / 2;
    }
    C[0] = carry;
    
    return C;
}

int main()
{
    while (1)
    {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);

        int *A = (int *) malloc(n*sizeof(int));
        int *B = (int *) malloc(n*sizeof(int));

        printf("Enter elements of A: ");
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        printf("Enter elements of B: ");
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        int *C = binary_addition(A, B, n);

        printf("Binary sum of A and B is: ");
        for (int i = 0; i < n + 1; i++) printf("%d ", C[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
    return 0;
}