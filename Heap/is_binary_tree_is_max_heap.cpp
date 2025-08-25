// Is Binary Tree is Heap
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};
void CreateBinaryTree(Node *&root)
{
    int data;
    cout << "Enter your Node Data:" << endl;
    cin >> data;

    if (data == -1)
    {
        return;
    }
    root = new Node(data);

    cout << "Enter your left Child Data : " << endl;
    CreateBinaryTree(root->left);

    cout << "Enter your right Child Data: " << endl;
    CreateBinaryTree(root->right);
}

bool isCBT(Node *root, int i, int nodeCount)
{
    if (root == NULL)
        return true;

    if (i >= nodeCount)
        return false;

    return isCBT(root->left, 2 * i + 1, nodeCount) &&
           isCBT(root->right, 2 * i + 2, nodeCount);
}

// Check if tree follows Max-Heap property
bool isMax(Node *root)
{
    // Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // Only left child exists
    if (root->right == NULL)
    {
        return (root->data >= root->left->data) && isMax(root->left);
    }

    // Both children exist
    return (root->data >= root->left->data &&
            root->data >= root->right->data &&
            isMax(root->left) &&
            isMax(root->right));
}

// Count total nodes
int totalCount(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + totalCount(root->left) + totalCount(root->right);
}

bool isBinaryTree(Node *&root)
{
    int index = 0;
    int nodeCount = totalCount(root);
    if (isCBT(root, index, nodeCount) && isMax(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = NULL;
    CreateBinaryTree(root);
    cout << "Is Binary Tree : " << isBinaryTree(root);

    return 0;
}