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
    void mergeTrees(Node *node,BinaryTree &newTree)
    {
        if (!node)
            return;
        mergeTrees(node->left,newTree);
        newTree.insertIntoTree(node->data);
        mergeTrees(node->right,newTree);
    }

    void mergeTrees(BinaryTree &newTree)
    {
        mergeTrees(root,newTree);
    }
};

int main()
{
    BinaryTree tree1,tree2,mergedTree;
    
    int tree1Values[] = {6, 2, 3, 4, 5};

    int tree2Values[] = {2, 1, 3, 7, 6};
    int size = sizeof(tree1Values) / sizeof(tree1Values[0]);
    for (int i = 0; i < size; i++)
    {
        tree1.insertIntoTree(tree1Values[i]);
        tree2.insertIntoTree(tree2Values[i]);
    }
    cout << "Inorder traversal(tree1): ";
    tree1.inorderTraversal();//made traversal function only to check if the values are inserted correctly
    cout << "Inorder traversal(tree2): ";
    tree2.inorderTraversal();
    tree1.mergeTrees(mergedTree);    
    tree2.mergeTrees(mergedTree);    
    cout << "Inorder traversal(merged tree): ";
    mergedTree.inorderTraversal();

    return 0;
}
