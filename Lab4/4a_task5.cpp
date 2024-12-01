#include<iostream>
using namespace std;

void combSort(int arr[], int n) {
    double shrinkFactor = 1.9;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = int(gap / shrinkFactor);
        if (gap < 1) gap = 1;
        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int prices[8] = {25, 1, 99, 10, 14, 82,56, 65};
    cout<<"Before Sorting: ";
    print(prices, 8);
    cout<<"\nAfter Sorting: ";
    combSort(prices, 8);
    print(prices, 8);
    return 0;
}
