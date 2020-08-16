#include <iostream>
#include <vector>

using namespace std;

class MinHeap
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
        if (pos > 0 && heap[pos] < heap[(pos-1)/2])
        {
            swap(&heap[pos], &heap[(pos-1)/2]);
            percolate_up((pos-1)/2);
        }
    }

    void percolate_down(int pos)
    {
        if(size > (2 * pos + 2) && heap[pos] > heap[2 * pos + 1] && heap[pos] > heap[2 * pos + 2])
        {
            if(heap[2 * pos + 1] > heap[2 * pos + 2])
            {
                swap(&heap[pos], &heap[2*pos+2]);
                percolate_down(2*pos+2);
            }
            else
            {
                swap(&heap[pos], &heap[2*pos+1]);
                percolate_down(2*pos+1);
            }
        }
        else if (size > (2 * pos + 1) && heap[pos] > heap[2 * pos + 1])
        {
            swap(&heap[pos], &heap[2*pos + 1]);
            percolate_down(2*pos + 1);
        }
        else if (size > (2 * pos + 2) && heap[pos] > heap[2 * pos + 2])
        {
            swap(&heap[pos], &heap[2*pos + 2]);
            percolate_down(2*pos + 2);
        }
    }

public:
    int size;
    MinHeap()
    {
        size = 0;
    }

    int build(int *A, int n)
    {
        for(int i = 0; i < n; i++)
            insert_element(A[i]);
        
        return 1;
    }

    void sort()
    {
        while(size > 0)
        {
            printf("%d ", get_root());
            delete_element(get_root());
        }
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

    void print()
    {
        for (int i = 0; i < size; i++)
            printf("%d ", heap[i]);
    }
};

int main()
{
    printf("<-- Data structure: MinHeap -->\n");
    MinHeap heap;
    while (1)
    {
        int choice;
        printf("1. Insert element\t2. Delete element\t3. Print heap\n");
        printf("4. Build heap\t5. Clear heap\t6. Get root element\n");
        printf("7. Heap sort\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int d;
            printf("Enter element: ");
            scanf("%d", &d);
            heap.insert_element(d);
        }
        else if(choice == 2)
        {
            if(heap.size == 0)
                printf("Heap is empty");
            else
            {
                int d;
                printf("Enter element to be deleted: ");
                scanf("%d", &d);
                
                if(heap.delete_element(d))
                    printf("Element deleted");
                else
                    printf("Element not found"); 
            }
        }
        else if (choice == 3)
        {
            if (heap.size == 0)
                printf("Heap is empty");
            else
                heap.print();
        }
        else if(choice == 4)
        {
            if (heap.size != 0)
                printf("Heap already exists, clear it first");
            else
            {
                int num;
                printf("Enter number of elements to be added: ");
                scanf("%d", &num);

                int *A = new int[num];

                printf("Enter elements: ");
                for(int i = 0; i < num; i++)
                    scanf("%d", &A[i]);

                if(heap.build(A, num))
                    printf("Build successful");
                else
                    printf("Build failed");
            }
        }
        else if(choice == 5)
        {
            if(heap.size == 0)
                printf("Heap doesn't exist in the first place");
            else
                heap.clear();
        }
        else if(choice == 6)
        {
            if(heap.size == 0)
                printf("Heap doesn't exist");
            else
                printf("The root element is: %d", heap.get_root());
        }
        else if(choice == 7)
        {
            if(heap.size == 0)
                printf("Heap doesn't exist");
            else
                heap.sort();
        }

        printf("\n\n");
    }
    return 0;
}