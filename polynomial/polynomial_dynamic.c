#include <stdio.h>
#include <stdlib.h>

int polynomial_naive(int *A, int degree, int x)
{
    int result = 0, temp = 1;

    for (int i = 0; i <= degree; i++)
    {
        result = result + (A[i] * temp);
        temp = temp * x;
    }
    return result;
}

int main()
{
    while (1)
    {
        int degree;
        printf("Enter degree of polynomial: ");
        scanf("%d", &degree);

        int *A = (int *)malloc((degree+1)*sizeof(int));

        printf("Enter a_0 upto a_%d: ", degree);
        for (int i = 0; i <= degree; i++) scanf("%d", &A[i]);

        int x;
        printf("Enter value to evaluate polynomial: ");
        scanf("%d", &x);

        printf("P(%d) = %d", x, polynomial_naive(A, degree, x));
        printf("\n\n");

        free(A);
    };
    return 0;
}