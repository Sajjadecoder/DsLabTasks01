#include <iostream>
using namespace std;

struct HashTableEntry {
    int key;
    int value;
    HashTableEntry* next;

    HashTableEntry(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMapTable {
private:
    static const int INITIAL_TABLE_SIZE = 10;
    int TABLE_SIZE;
    HashTableEntry** table;
    int elementsCount;

public:
    HashMapTable() : TABLE_SIZE(INITIAL_TABLE_SIZE), elementsCount(0) {
        table = new HashTableEntry*[TABLE_SIZE]();
    }

    int HashFunc(int k) {
        return k % TABLE_SIZE;
    }

    double LoadFactor() const {
        return 1.0 * elementsCount / TABLE_SIZE;
    }

    void ResizeTable(int newSize) {
        HashTableEntry** newTable = new HashTableEntry*[newSize]();

        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashTableEntry* current = table[i];
            while (current != nullptr) {
                int newHash = current->key % newSize;
                HashTableEntry* next = current->next;
                current->next = newTable[newHash];
                newTable[newHash] = current;
                current = next;
            }
        }
        delete[] table;
        table = newTable;
        TABLE_SIZE = newSize;
    }

    void Insert(int k, int v) {
        int hash = HashFunc(k);
        HashTableEntry* newEntry = new HashTableEntry(k, v);

        if (table[hash] == nullptr) {
            table[hash] = newEntry;
        } else {
            HashTableEntry* current = table[hash];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newEntry;
        }

        elementsCount++; 

        if (LoadFactor() > 0.7) {
            int newSize = TABLE_SIZE * 2;
            ResizeTable(newSize);
        }
    }

    int SearchKey(int k) {
        int hash = HashFunc(k);

        HashTableEntry* current = table[hash];
        while (current != nullptr) {
            if (current->key == k) {
                return current->value;
            }
            current = current->next;
        }

        return -1;
    }

    void Remove(int k) {
        int hash = HashFunc(k);

        HashTableEntry* current = table[hash];
        HashTableEntry* prev = nullptr;

        while (current != nullptr && current->key != k) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                table[hash] = current->next;
            }
            delete current;
            elementsCount--;
        }
    }

    void PrintTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Index " << i << ": ";
            HashTableEntry* current = table[i];
            while (current != nullptr) {
                cout << "(Key: " << current->key << ", Value: " << current->value << ") -> ";
                current = current->next;
            }
            cout << "Null" << endl;
        }
    }

    ~HashMapTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashTableEntry* current = table[i];
            while (current != nullptr) {
                HashTableEntry* next = current->next;
                delete current;
                current = next;
            }
            table[i] = nullptr;
        }
        delete[] table;
    }
};

int main() {
    HashMapTable hashTable;
    int Keys[] = {20, 34, 45, 70, 56};
    int n = 5;
    for (int i = 0; i < n; i++) {
        //(i*10)+i are the elements that are being inserted
        hashTable.Insert(Keys[i], (i * 10) + i); 
    }
    
    cout << "Hash Table After Insertions:" << endl;
    hashTable.PrintTable();

    int value = hashTable.SearchKey(56);
    if (value != -1) {
        cout << "Value for searched key is: " << value << endl;
    } else {
        cout << "Key not found." << endl;
    }
    hashTable.Remove(45);
    cout<<"hash table after deleting 45\n";
    hashTable.PrintTable();
}
