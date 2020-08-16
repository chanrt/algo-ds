#include <iostream>
#include <vector>

using namespace std;

class MaxPriorityQueue
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
    MaxPriorityQueue()
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

    int increase(int key, int value)
    {
        for(int i = 0; i < size; i++)
        {
            if(heap[i] == key)
            {
                heap[i] += value;
                percolate_up(i);
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
    MaxPriorityQueue queue;
    while (1)
    {
        int choice;
        printf("1. Insert element\t2. Delete element\t3. Print queue\n");
        printf("4. Build queue\t5. Clear queue\t6. Get root element\n");
        printf("7. Print priority order\t8. Increase element value\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int d;
            printf("Enter element: ");
            scanf("%d", &d);
            queue.insert_element(d);
        }
        else if(choice == 2)
        {
            if(queue.size == 0)
                printf("Queue is empty");
            else
            {
                int d;
                printf("Enter element to be deleted: ");
                scanf("%d", &d);
                
                if(queue.delete_element(d))
                    printf("Element deleted");
                else
                    printf("Element not found"); 
            }
        }
        else if (choice == 3)
        {
            if (queue.size == 0)
                printf("Heap is empty");
            else
                queue.print();
        }
        else if(choice == 4)
        {
            if (queue.size != 0)
                printf("Queue already exists, clear it first");
            else
            {
                int num;
                printf("Enter number of elements to be added: ");
                scanf("%d", &num);

                int *A = new int[num];

                printf("Enter elements: ");
                for(int i = 0; i < num; i++)
                    scanf("%d", &A[i]);

                if(queue.build(A, num))
                    printf("Build successful");
                else
                    printf("Build failed");
            }
        }
        else if(choice == 5)
        {
            if(queue.size == 0)
                printf("Queue doesn't exist in the first place");
            else
                queue.clear();
        }
        else if(choice == 6)
        {
            if(queue.size == 0)
                printf("Queue doesn't exist");
            else
                printf("The root element is: %d", queue.get_root());
        }
        else if(choice == 7)
        {
            if(queue.size == 0)
                printf("Queue doesn't exist");
            else
                queue.sort();
        }
        else if(choice == 8)
        {
            if(queue.size == 0)
                printf("Queue doesn't exist yet");
            else
            {
                int key, value;
                printf("Enter element whose value should be increased: ");
                scanf("%d",&key);
                printf("Enter increase: ");
                scanf("%d",&value);
                
                if(queue.increase(key, value))
                    printf("Value of element %d increased to %d", key, key+value);
                else
                    printf("Element %d not found", key);
            }
        }

        printf("\n\n");
    }
    return 0;
}