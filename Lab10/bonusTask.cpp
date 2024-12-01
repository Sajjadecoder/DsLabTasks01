#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void getCodes(Node* root, string codes[], string current) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        codes[root->ch] = current;
        return;
    }

    getCodes(root->left, codes, current + '0');
    getCodes(root->right, codes, current + '1');
}

void decode(Node* root, const string& encoded) {
    Node* current = root;
    string decoded = "";

    for (int i = 0; i < encoded.length(); i++) {
        current = (encoded[i] == '0') ? current->left : current->right;

        if (current->left == NULL && current->right == NULL) {
            decoded += current->ch;
            current = root;
        }
    }

    cout << "\nDecoded: " << decoded << endl;
}

void huffman(string text, Node*& root, string& encoded) {
    int freq[256] = {0};

    for (int i = 0; i < text.length(); i++) {
        freq[text[i]]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(new Node((char)i, freq[i]));
        }
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    root = pq.top();

    string codes[256];
    getCodes(root, codes, "");

    cout << "Codes:\n";
    for (int i = 0; i < 256; i++) {
        if (!codes[i].empty()) {
            cout << (char)i << ": " << codes[i] << endl;
        }
    }

    encoded = "";
    for (int i = 0; i < text.length(); i++) {
        encoded += codes[text[i]];
    }

    cout << "Encoded: " << encoded << endl;
}

int main() {

    string text ="SAJJAD";
    Node* root = NULL;
    string encoded;

    huffman(text, root, encoded); 

    decode(root, encoded); 
}