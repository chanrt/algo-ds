#include <stdio.h>
#include <stdlib.h>

int **matrix_multiply_recursive(int **A, int **B, int **C, int rows1, int cols1, int rows2, int cols2)
{
    static int i = 0, j = 0, k = 0;

    if (i >= rows1) return C;

    if (j < cols2)
    {
        if (k < cols1)
        {
            C[i][j] += A[i][k] * B[k][j];
            k++;
             return matrix_multiply_recursive(A, B, C, rows1, cols1, rows2, cols2);
        }

        k = 0;
        j++;
        return matrix_multiply_recursive(A, B, C, rows1, cols1, rows2, cols2);
    }

    j = 0;
    i++;
    return matrix_multiply_recursive(A, B, C, rows1, cols1, rows2, cols2);
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

        if (cols1 != rows2)
        {
            printf("Matrix multiplication not possible between matrices of these dimensions\n");
            free(A);
            free(B);
            continue;
        }

        int **C = (int **)malloc(rows1*sizeof(int));
        for (int i = 0; i < rows1; i++)
            C[i] = (int *)malloc(cols2*sizeof(int));

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
                C[i][j] = 0;
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

        C = matrix_multiply_recursive(A, B, C, rows1, cols1, rows2, cols2);

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
        free(C);
    };
    return 0;
}