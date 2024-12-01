#include <iostream>
using namespace std;
#define MAX_HEAP_SIZE 1000

void heapifyMax(int array[], int arraySize, int maxElement)
{
    int largest = maxElement;
    int left = 2 * maxElement + 1;
    int right = 2 * maxElement + 2;

    if (left < arraySize && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < arraySize && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != maxElement)
    {
        swap(array[maxElement], array[largest]);

        heapifyMax(array, arraySize, largest);
    }
}
void heapifyMin(int array[], int arraySize, int minElement)
{
    int smallest = minElement;
    int left = 2 * minElement + 1;
    int right = 2 * minElement + 2;

    if (left < arraySize && array[left] < array[smallest])
    {
        smallest = left;
    }

    if (right < arraySize && array[right] < array[smallest])
    {
        smallest = right;
    }

    if (smallest != minElement)
    {
        swap(array[minElement], array[smallest]);

        heapifyMin(array, arraySize, smallest);
    }
}

void buildHeap(int array[], int arraySize, bool isMaxHeap)
{

    int startIndex = (arraySize / 2) - 1;
    if (isMaxHeap)
    {

        for (int i = startIndex; i >= 0; i--)
        {
            heapifyMax(array, arraySize, i);
        }
    }
    else
    {
        for (int i = startIndex; i >= 0; i--)
        {
            heapifyMin(array, arraySize, i);
        }
    }
}

void printHeap(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[MAX_HEAP_SIZE] = {7, 1, 6, 2, 5, 9, 10, 2};
    int arraySize = 8;

    buildHeap(array, arraySize, true);
    cout << "Max Heap: ";
    printHeap(array, arraySize);
    buildHeap(array, arraySize, false);
    cout << "Min Heap: ";
    printHeap(array, arraySize);
    return 0;
}