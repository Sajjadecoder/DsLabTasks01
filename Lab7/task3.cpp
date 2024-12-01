#include <iostream>
using namespace std;

void merge(int *arr, int start, int end, int mid, bool ascending)
{
    int *tempArr = new int[end - start + 1];
    int low = start;
    int high = mid + 1;
    int index = 0;
    if (ascending)
    {

        while (low <= mid && high <= end)
        {
            if (arr[low] < arr[high])
            {
                tempArr[index++] = arr[low++];
            }
            else
            {
                tempArr[index++] = arr[high++];
            }
        }
    }else{
        while (low <= mid && high <= end)
        {
            if (arr[low] > arr[high])
            {
                tempArr[index++] = arr[low++];
            }
            else
            {
                tempArr[index++] = arr[high++];
            }
        }

    }
    while (low <= mid)
    {
        tempArr[index++] = arr[low++];
    }
    while (high <= end)
    {
        tempArr[index++] = arr[high++];
    }
    index = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = tempArr[index++];
    }
}
void mergeSort(int *arr, int start, int end, bool ascending)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid, ascending);
    mergeSort(arr, mid + 1, end, ascending);
    merge(arr, start, end, mid, ascending);
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> array[i];
    }

    cout << "Array before sorting: ";
    print(array, n);
    mergeSort(array, 0, n - 1, true);
    cout << "Array after sorting(ascending): ";
    print(array, n);
    mergeSort(array, 0, n - 1, false);
    cout << "Array after sorting(descending): ";
    print(array, n);

    delete[] array;
    return 0;
}
