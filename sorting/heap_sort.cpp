#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    void swap(int *x, int *y)
    {
        int t = *x;
        *x = *y;
        *y = t;
    }

    void percolate_up(int pos)
    {
        if (pos > 0 && heap[pos] > heap[(pos-1)/2])
        {
            swap(&heap[pos], &heap[(pos-1)/2]);
            percolate_up((pos-1)/2);
        }
    }

    void percolate_down(int pos)
    {
        if(size > (2 * pos + 2) && heap[pos] < heap[2 * pos + 1] && heap[pos] < heap[2 * pos + 2])
        {
            if(heap[2 * pos + 1] > heap[2 * pos + 2])
            {
                swap(&heap[pos], &heap[2*pos+1]);
                percolate_down(2*pos+1);
            }
            else
            {
                swap(&heap[pos], &heap[2*pos+2]);
                percolate_down(2*pos+2);
            }
        }
        else if (size > (2 * pos + 1) && heap[pos] < heap[2 * pos + 1])
        {
            swap(&heap[pos], &heap[2*pos + 1]);
            percolate_down(2*pos + 1);
        }
        else if (size > (2 * pos + 2) && heap[pos] < heap[2 * pos + 2])
        {
            swap(&heap[pos], &heap[2*pos + 2]);
            percolate_down(2*pos + 2);
        }
    }

public:
    int size;
    MaxHeap()
    {
        size = 0;
    }

    int build(int *A, int n)
    {
        for(int i = 0; i < n; i++)
            insert_element(A[i]);
        
        return 1;
    }

    int *sort()
    {
        int *A = new int[size];
        int i = 0;

        while(size > 0)
        {
            A[i] = heap[0];
            i++;
            delete_element(heap[0]);
        }
        return A;
    }

    void insert_element(int d)
    {
        heap.push_back(d);
        percolate_up(size);
        size++;
    }

    int delete_element(int d)
    {
        for (int i = 0; i < size; i++)
        {
            if (heap[i] == d)
            {
                swap(&heap[i], &heap[size-1]);
                size--;
                percolate_down(i);
                return 1;
            }
        }
        return 0;
    }

    void clear()
    {
        size = 0;
    }

    int get_root()
    {
        return heap[0];
    }
};

int main()
{
    MaxHeap heap;
    while (1)
    {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);

        int *A = (int *)malloc(n*sizeof(int));

        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);

        heap.clear();
        heap.build(A, n);
        A = heap.sort();

        printf("Sorted elements: ");
        for (int i = n-1; i > -1; i--) printf("%d ", A[i]);
        printf("\n\n");

        free(A);
    };
    return 0;
}