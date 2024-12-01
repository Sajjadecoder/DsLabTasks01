#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
struct HashTableEntry
{
    int key;
    int value;
    HashTableEntry *next;

    HashTableEntry(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMapTable
{
private:
    static const int INITIAL_TABLE_SIZE = 10;
    int TABLE_SIZE;
    HashTableEntry **table;
    int elementsCount;

public:
    HashMapTable(int N) : TABLE_SIZE(N), elementsCount(0)
    {
        table = new HashTableEntry *[TABLE_SIZE]();
    }

    int HashFunc(int k)
    {
        if (k < 0)
        {
            return ((k % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
        }

        return k % TABLE_SIZE;
    }

    double LoadFactor() const
    {
        return 1.0 * elementsCount / TABLE_SIZE;
    }

    void ResizeTable(int newSize)
    {
        HashTableEntry **newTable = new HashTableEntry *[newSize]();

        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashTableEntry *current = table[i];
            while (current != nullptr)
            {
                int newHash = current->key % newSize;
                HashTableEntry *next = current->next;
                current->next = newTable[newHash];
                newTable[newHash] = current;
                current = next;
            }
        }
        delete[] table;
        table = newTable;
        TABLE_SIZE = newSize;
    }

    void Insert(int k, int v)
    {
        int hash = HashFunc(k);
        HashTableEntry *newEntry = new HashTableEntry(k, v);

        if (table[hash] == nullptr)
        {
            table[hash] = newEntry;
        }
        else
        {
            HashTableEntry *current = table[hash];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newEntry;
        }

        elementsCount++;

        if (LoadFactor() > 0.7)
        {
            int newSize = TABLE_SIZE * 2;
            ResizeTable(newSize);
        }
    }

    int SearchKey(int k)
    {
        int hash = HashFunc(k);

        HashTableEntry *current = table[hash];
        while (current != nullptr)
        {
            if (current->key == k)
            {
                return current->value;
            }
            current = current->next;
        }

        return -1;
    }

    void Remove(int k)
    {
        int hash = HashFunc(k);

        HashTableEntry *current = table[hash];
        HashTableEntry *prev = nullptr;

        while (current != nullptr && current->key != k)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                table[hash] = current->next;
            }
            delete current;
            elementsCount--;
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            cout << "Index " << i << ": ";
            HashTableEntry *current = table[i];
            while (current != nullptr)
            {
                cout << "(Key: " << current->key << ", Value: " << current->value << ") -> ";
                current = current->next;
            }
            cout << "Null" << endl;
        }
    }

    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashTableEntry *current = table[i];
            while (current != nullptr)
            {
                HashTableEntry *next = current->next;
                delete current;
                current = next;
            }
            table[i] = nullptr;
        }
        delete[] table;
    }
};

bool checkTriplet(HashMapTable &hashTable, int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int num1 = arr[i];
        int num2 = arr[i + 1];
        if (hashTable.SearchKey((num1 + num2) * -1) == 1)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter N: ";
    cin >> n;

    int *nums = new int[n];
    HashMapTable hashTable(n * 2);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    mergeSort(nums, 0, n - 1);//nlogn
    for (int i = 0; i < n; i++)
    {
        hashTable.Insert(nums[i], 1); // 1 represents that number exists
    }

    cout << checkTriplet(hashTable, nums, n);
    //time complexity of the code is O(nlogn)
    delete[] nums;
    return 0;
}
