#include <iostream>
using namespace std;

int partition(int *array, int start, int end, bool ascending)
{
    int pivot = array[(start + end) / 2];
    while (start <= end)
    {
        if (ascending)
        {
            while (array[start] > pivot)
            {
                start++;
            }
            while (array[end] < pivot)
            {
                end--;
            }
        }
        else{
            while (array[start] < pivot)
            {
                start++;
            }
            while (array[end] > pivot)
            {
                end--;
            }

        }
        if (start <= end)
        {
            swap(array[start], array[end]);
            start++;
            end--;
        }
    }
    return start;
}

void quickSort(int *arr, int start, int end, bool ascending)
{
    if (start < end)
    {
        int j = partition(arr, start, end, ascending);
        quickSort(arr, start, j - 1, ascending);
        quickSort(arr, j, end, ascending);
    }
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

    cout << "Array after sorting(ascending): ";
    quickSort(array, 0, n - 1, true);
    print(array, n);

    cout << "Array after sorting(descending): ";
    quickSort(array, 0, n - 1, false);
    print(array, n);

    delete[] array;
    return 0;
}
