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

    int findCeil(Node *node, int target)
    {
        int ceil = -1;
        while (node)
        {
            if (node->data == target)
                return node->data;
            else if (node->data > target)
            {
                ceil = node->data;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return ceil;
    }

    int findFloor(Node *node, int target)
    {
        int floor = -1;
        while (node)
        {
            if (node->data == target)
                return node->data;
            else if (node->data < target)
            {
                floor = node->data;
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        return floor;
    }

    void findCeilOrFloor(int X, bool isCeil)
    {
        int target,result;
        if (isCeil==true)
        {
            target = X+1;
            result = findCeil(root,target);
        }else{
            target = X-1;
            result =findFloor(root,target);

        }
        

        if (result != -1)
        {
            cout << (isCeil ? "Ceil" : "Floor") << " value closest to " << X << " is: " << result << endl;
            int count = 0;
            findMultipleOccurrences(root, result, count);
            cout << "Occurrences of " << result << ": " << count << endl;
        }
        else
        {
            cout << "No suitable value found." << endl;
        }
    }

    void findMultipleOccurrences(Node *node, int value, int &count)
    {
        if (!node)
            return;
        findMultipleOccurrences(node->left, value, count);
        if (node->data == value)
            count++;
        findMultipleOccurrences(node->right, value, count);
    }
};

int main()
{
    BinaryTree tree;
    int arr[] = {10, 11, 7, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        tree.insertIntoTree(arr[i]);
    }

    cout << "Inorder traversal: ";
    tree.inorderTraversal();

    int X, ch;
    cout << "Enter a number: ";
    cin >> X;
    cout << "Enter 1 for Ceil\nEnter 2 for Floor\nChoice: ";
    cin >> ch;

    if (ch == 1)
    {
        tree.findCeilOrFloor(X, true);
    }
    else if (ch == 2)
    {
        tree.findCeilOrFloor(X, false);
    }

    return 0;
}
