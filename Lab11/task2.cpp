#include <iostream>
using namespace std;

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

int main()
{
    int N, K;
    cout<<"Enter N: ";
    cin >> N ;
    cout<<"Enter K: ";
    cin>>K;
    HashMapTable hashTable(N * 2);
    int count = 0;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        hashTable.Insert(arr[i], i);
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < K && hashTable.SearchKey(K - arr[i]) >= 0 && i != hashTable.SearchKey(K - arr[i]))
        {
            count++;
        }
    }
   cout << endl;
    cout << "Count: " << count;
    return 0;
}