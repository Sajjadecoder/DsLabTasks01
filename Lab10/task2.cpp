#include <iostream>
using namespace std;

void heapifyMin(int *arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMinHeap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--){

        heapifyMin(arr, n, i);
    }
}

void heapifyMax(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildMaxHeap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--){

        heapifyMax(arr, n, i);
    }
}

void heapSort(int *arr, int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}
void printHeap(int *arr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n =10;

    buildMinHeap(arr, n);
    cout<<"Min Heap: ";
    printHeap(arr,n);
    cout<<"Value Deleted: ";
    cout<<arr[0]<<endl;
    arr[0] = arr[n - 1];
    n--;

    buildMaxHeap(arr, n);
    cout<<"Max Heap: ";
    printHeap(arr,n);
    heapSort(arr, n);
    cout<<"Sorted Array: ";
    printHeap(arr,n);
    return 0;
}
