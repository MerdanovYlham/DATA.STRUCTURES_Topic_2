#include <algorithm>

class BinaryHeap
{
private:
    int *arr;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:
    BinaryHeap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    void insert(int key)
    {
        if (size == capacity)
            return;

        int i = size++;
        arr[i] = key;

        while (i != 0 && arr[parent(i)] < arr[i])
        {
            std::swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    int extractMax()
    {
        if (size <= 0)
            return -1;

        if (size == 1)
            return arr[--size];

        int root = arr[0];
        arr[0] = arr[--size];
        heapify(0);

        return root;
    }

    bool search(int key)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == key)
                return true;
        return false;
    }

    void deleteKey(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                arr[i] = arr[--size];
                heapify(i);
                return;
            }
        }
    }
};