#include <iostream>
using namespace std;
void shellSort(int *weights, int size)
{
    int n = size;
    for (int gap = n / 2; gap > 0; gap = (gap / 3) + 1)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = weights[i];
            int j = i;
            while (j >= gap && weights[j - gap] > temp)
            {
                weights[j] = weights[j - gap];

                j -= gap;
            }

            weights[j] = temp;
        }
        if (gap == 1)
            break;
    }
}

void print(int *weights, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << weights[i] << " ";
    }
    cout << endl;
}

int main()
{
    int weights[8] = {15, 10, 500, 16, 17, 100, 15, 34};
    cout << "Before sorting:";
    print(weights, 8);
    cout << endl;
    shellSort(weights, 8);
    cout << "After Sorting:";
    print(weights, 8);
    return 0;
}
