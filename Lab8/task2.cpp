#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class BinaryTree
{
    Node *root;

public:
    BinaryTree() : root(NULL) {}

    Node *insertIntoBST(Node *node, int val)
    {
        if (node == NULL)
            return new Node(val);
        if (val < node->data)
        {
            node->left = insertIntoBST(node->left, val);
        }
        else
        {
            node->right = insertIntoBST(node->right, val);
        }
        return node;
    }

    void insert(int val)
    {
        root = insertIntoBST(root, val);
    }

    void inorderToList(Node *node, ListNode *&head, ListNode *&tail)
    {
        if (node == NULL)
            return;

        inorderToList(node->left, head, tail);

        ListNode *newNode = new ListNode(node->data);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        inorderToList(node->right, head, tail);
    }

    Node *buildFullCompleteTree(ListNode *&head, int n)
    {
        if (n <= 0 || head == NULL)
            return NULL;

        Node *leftSubtree = buildFullCompleteTree(head, n / 2);
        Node *root = new Node(head->data);
        root->left = leftSubtree;
        head = head->next;
        root->right = buildFullCompleteTree(head, n - n / 2 - 1);

        return root;
    }
    void makeFullAndComplete()
    {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        inorderToList(root, head, tail);
        int count = 0;
        for (ListNode *temp = head; temp; temp = temp->next)
        {
            count++;
        }
        root = buildFullCompleteTree(head, count);
    }
    void inorderPrint(Node *node)
    {
        if (node == NULL)
            return;
        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }

    void inorderPrint()
    {
        inorderPrint(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        tree.insert(arr[i]);
    }

    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    cout << "Inorder traversal before making full and complete: ";
    tree.makeFullAndComplete();
    tree.inorderPrint();
    cout << "Inorder traversal after making full and complete: ";
    tree.inorderPrint();

    return 0;
}
