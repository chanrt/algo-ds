#include <stdio.h>
#include <stdlib.h>

int **matrix_multiply_usual(int **A, int **B, int rows1, int cols1, int rows2, int cols2)
{
    int sum;

    int **C = (int **)malloc(rows1*sizeof(int *));
    for (int i = 0; i < rows1; i++)
        C[i] = (int *)malloc(cols2*sizeof(int));

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            sum = 0;
            for (int k = 0; k < cols1; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    }

    return C;
}

int main()
{
    while (1)
    {
        int rows1, cols1;
        printf("Enter size of  matrix A (no. of rows, followed by no. of cols): ");
        scanf("%d %d", &rows1, &cols1);

        int rows2, cols2;
        printf("Enter size of  matrix B (no. of rows, followed by no. of cols): ");
        scanf("%d %d", &rows2, &cols2); 

        int **A = (int **)malloc(rows1*sizeof(int *));
        for (int i = 0; i < rows1; i++)
            A[i] = (int *)malloc(cols1*sizeof(int));

        int **B = (int **)malloc(rows2*sizeof(int *));
        for (int i = 0; i < rows2; i++)
            B[i] = (int *)malloc(cols2*sizeof(int));

        if(cols1 != rows2)
        {
            printf("Matrix multiplication not possible between matrices of these dimensions\n");
            free(A);
            free(B);
            continue;
        }

        printf("Enter elements of A (row-wise):\n");
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols1; j++)
                scanf("%d", &A[i][j]);
        }

        printf("Enter elements of B (row-wise):\n");
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < cols2; j++)
                scanf("%d", &B[i][j]);
        }

        int **C = matrix_multiply_usual(A, B, rows1, cols1, rows2, cols2);

        printf("Result:\n");
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
        printf("\n\n");

        free(A);
        free(B);
    };
    return 0;
}