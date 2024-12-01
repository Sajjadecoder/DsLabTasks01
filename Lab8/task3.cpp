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
    bool searchNum(Node *root,int val){
        if (root==NULL)
        {
            return false;
        }
        if (val==root->data)
        {
            return true; 
        }
        if (val<root->data)
        {
            return searchNum(root->left,val); 
        }
        else{
            return searchNum(root->right,val);
        }        
        
    }
    bool searchNum(int val){
        return searchNum(root,val); 
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

    cout << "Initial elements in the tree: ";
    tree.inorderTraversal();//made traversal function only to check if the values are inserted correctly
    cout<<"Enter a number to search in tree: ";
    int num;
    cin>>num;
    if (!tree.searchNum(num))
    {
        cout<< num<<" not found\nWill insert now\n";
        tree.insertIntoTree(num);
        cout<< num<<" inserted in the tree\n";
        cout<<"Inorder traversal: ";
        tree.inorderTraversal();
        return 0;
    }else{
        cout<<num<<" exists in the tree\n";
    }
    
    return 0;
}
