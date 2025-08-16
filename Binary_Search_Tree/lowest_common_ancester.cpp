// Lowest Common Ancestor in BST
// Implementation of Binar Search Tree
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

Node *InsertData(Node *&root, int data)
{
    // for first Node
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // left Part
    if (root->data > data)
    {
        root->left = InsertData(root->left, data);
    }
    else
    {
        root->right = InsertData(root->right, data);
    }
    return root;
}

void CreateBST(Node *&root)
{
    int data;

    cin >> data;

    while (data != -1)
    {
        root = InsertData(root, data);
        cin >> data;
    }
}

Node *LCA(Node *&root, int p, int q)
{

    if (root == NULL)
    {
        return NULL;
    }
    // 4 Cases
    if (p < root->data && q < root->data)
    {
        root->left = LCA(root->left, p, q);
    }
    else if (p > root->data && q > root->data)
    {
        root->right = LCA(root->right, p, q);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter your data: ";
    CreateBST(root);

    Node *result = LCA(root, 70, 160);
    cout << "LCA : " << result->data;

    return 0;
}
