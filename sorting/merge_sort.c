#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int m, int n, int p)
{
    if (DEBUG) printf("In merge function\n");

    int size1 = n-m+1, size2 = p-n;
    int *L = (int *)malloc(size1*sizeof(int));
    int *M = (int *)malloc(size2*sizeof(int));
    if (DEBUG) printf("Temporary arrays malloced\n");

    for (int i = 0; i < size1; i++) L[i] = A[m+i];
    for (int i = 0; i < size2; i++) M[i] = A[n+1+i];
    if (DEBUG) printf("Temporary copies created\n");

    int ptr1 = 0, ptr2 = 0, ptr = m;
    while (ptr1 < size1 && ptr2 <size2)
    {
        if (L[ptr1] > M[ptr2])
            A[ptr++] = M[ptr2++];
        else
            A[ptr++] = L[ptr1++];
    }
    if (DEBUG) printf("Mainstream copying done\n");

    while (ptr1 < size1) A[ptr++] = L[ptr1++];
    while (ptr2 < size2) A[ptr++] = M[ptr2++];
    if (DEBUG) printf("Rest of the array copied\n");
}

void merge_sort(int *A, int m, int p)
{
    if (DEBUG) printf("merge_sort called\n");

    if (m < p)
    {
        int n = (m + p) / 2;
        merge_sort(A, m, n);
        merge_sort(A, n+1, p);
        merge(A, m, n, p);
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

        merge_sort(A, 0, n-1);

        printf("Sorted elements: ");
        for (int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}