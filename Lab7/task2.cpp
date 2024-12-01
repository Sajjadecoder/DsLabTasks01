#include<iostream>
using namespace std;

int getMax(int *arr, int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void countSort(int *arr, int n, int exp, bool ascending) {
    int *output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    if (ascending) {
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
    } else {
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int *arr, int n, bool ascending) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, n, exp, ascending);
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> array[i];
    }
    
    cout << "Array before sorting: ";
    print(array, n);

    radixSort(array, n, true);
    cout << "Array after sorting (ascending): ";
    print(array, n);

    radixSort(array, n, false);
    cout << "Array after sorting (descending): ";
    print(array, n);

    delete[] array;
    return 0;
}
