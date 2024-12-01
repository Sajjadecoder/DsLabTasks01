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

class BinaryTree
{
    Node *root;

public:
    BinaryTree() { root = NULL; }

    void insertIntoTree(int val)
    {
        if (!root)
        {
            root = new Node(val);
            return;
        }

        Node *temp = root;
        while (1)
        {
            if (val < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node(val);
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node(val);
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void inorderTraversal(Node *node)
    {
        if (!node)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
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
        tree.insertIntoTree(arr[i]);
    }

    cout << "Inorder traversal: ";
    tree.inorderTraversal();//made traversal function only to check if the values are inserted correctly
    
    return 0;
}
