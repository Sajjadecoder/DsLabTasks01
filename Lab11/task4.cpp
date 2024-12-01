#include <iostream>
using namespace std;
struct HashNode {
    char key;
    bool isPresent;
    HashNode() : key(0), isPresent(false) {}
};
class CustomHashTable {
private:
    static const int TABLE_SIZE= 256;
    HashNode table[TABLE_SIZE];


    int hashFunction(char key) {
        return key % TABLE_SIZE;
    }


public:
    void insert(char key) {
        int index= hashFunction(key);
        while (table[index].isPresent) {
            index= (index + 1) % TABLE_SIZE;
        }
        table[index].key= key;
        table[index].isPresent= true;
    }


    bool contains(char key) {
        int index= hashFunction(key);
        int startIndex= index;
        while (table[index].isPresent) {
            if (table[index].key== key) return true;
            index= (index + 1) % TABLE_SIZE;
            if (index== startIndex) break;
        }
        return false;
    }
};


void matchNutsAndBolts(char nuts[], char bolts[], int N) {
    char order[]= {'#', '$', '%', '&', '*', '@', '^', '~'};
    CustomHashTable hashTable;


    for (int i= 0; i < N; i++) {
        hashTable.insert(nuts[i]);
    }


    int index= 0;
    for (int i= 0; i < 8; i++) {
        if (hashTable.contains(order[i])) {
            nuts[index]= order[i];
            bolts[index]= order[i];
            index++;
        }
    }
}


int main() {
    int N= 5;
    char nuts[]= {'@', '%', '$', '#', '^'};
    char bolts[]= {'%', '@', '#', '$', '^'};


    matchNutsAndBolts(nuts, bolts, N);


    for (int i= 0; i < N; i++) {
        cout<<nuts[i]<<" ";
    }
    cout<<endl;


    for (int i= 0; i < N; i++) {
        cout<<bolts[i]<<" ";
    }
    cout<<endl;


    return 0;
}