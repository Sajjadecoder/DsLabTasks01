#include <iostream>
using namespace std;
#define nl cout << endl

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node *node)
{
    if (!node)
    {
        return 0;
    }
    return node->height;
}

int getBalance(Node *node)
{
    return (getHeight(node->left) - getHeight(node->right));
}

Node *rightRotate(Node *node)
{
    Node *child = node->left;
    Node *childRight = child->right;
    child->right = node;
    node->left = childRight;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *leftRotate(Node *node)
{
    Node *child = node->right;
    Node *childLeft = child->left;
    child->left = node;
    node->right = childLeft;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insertIntoTree(Node *&root, int val)
{
    if (!root)
    {
        return new Node(val);
    }
    if (root->data > val)
    {
        root->left = insertIntoTree(root->left, val);
    }
    else
    {
        root->right = insertIntoTree(root->right, val);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1)
    {
        if (val < root->left->data)
        {
            return rightRotate(root);
        }
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    else if (balance < -1)
    {
        if (val > root->right->data)
        {
            return leftRotate(root);
        }
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    else
    {
        return root;
    }
}

Node *deleteNode(Node *&root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (!root->right && !root->left)
        {
            delete root;
            return NULL;
        }
        if (root->right && !root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right && root->left)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        if (balance > 1)
        {
            if (getBalance(root->left) >= 0)
            {
                return rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (balance < -1)
        {
            if (getBalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        else
        {
            return root;
        }
    }
    return root;
}

void inOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
bool isPresent(Node *root, int key, int &index)
{
    if (!root)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    index++;
    if (root->data < key)
    {
        return isPresent(root->right, key, index);
    }
    else
    {
        return isPresent(root->left, key, index);
    }
}
int findKthSmallest(Node *root, int &k)
{
    if (!root)
    {
        return -1;
    }
    int left = findKthSmallest(root->left, k);
    if (left != -1)
    {
        return left;
    }
    if (--k == 0)
    {
        return root->data;
    }
    return findKthSmallest(root->right, k);
}

int findKthLargest(Node *root, int &k)
{
    if (!root)
    {
        return -1;
    }
    int right = findKthLargest(root->right, k);
    if (right != -1)
    {
        return right;
    }
    if (--k == 0)
    {
        return root->data;
    }
    return findKthLargest(root->left, k);
}

void printNodeSubtreeHeights(Node* root) {
    if (!root) return;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    cout << "Node " << root->data << ":\nLeft Height = " << leftHeight 
         << "\nRight Height = " << rightHeight ;nl;nl;

    printNodeSubtreeHeights(root->left);
    printNodeSubtreeHeights(root->right);
}

int main()
{
    //(did all the parts in a single file since the deletion/insertion code was same for all the 5 tasks)

    Node *root = NULL;
    for (int i = 1; i <= 7; i++)
    {
        root = insertIntoTree(root, i);
    }
    cout << "Inorder before deletion: ";
    inOrderTraversal(root);
    nl;
    cout << "Preorder before deletion: ";
    preOrderTraversal(root);
    nl;
    cout << "PostOrder before deletion: ";
    postOrderTraversal(root);
    nl;
    nl;
    deleteNode(root, 3);
    cout << "Inorder after deleting 3: ";
    inOrderTraversal(root);
    nl;
    cout << "Preorder after deleting 3: ";
    preOrderTraversal(root);
    nl;
    cout << "PostOrder after deleting 3: ";
    postOrderTraversal(root);
    nl;
    int index = 0;
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    if (isPresent(root, key, index))
    {
        cout << key << " found on index " << index;
        nl;
    }
    else
    {
        cout << "Inserted the key " << key << " in the tree\n";
        root = insertIntoTree(root, key);
        cout << "Inorder travsersal of the Tree after inserting the key: ";
        inOrderTraversal(root);
    }
    nl;
    int k;
    cout << "Enter k for kth smallest: ";
    cin >> k;
    int kthSmallest = findKthSmallest(root, k);
    cout << "Kth Smallest element is: " << kthSmallest << endl;

    cout << "Enter k for kth largest: ";
    cin >> k;
    int kthLargest = findKthLargest(root, k);
    cout << "Kth Largest element is: " << kthLargest << endl;
    printNodeSubtreeHeights(root);

    return 0;
}
