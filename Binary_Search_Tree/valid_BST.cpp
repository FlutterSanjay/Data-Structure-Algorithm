// Valid BST
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
    if (root == NULL)
    {
        return NULL;
    }

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
    cout << "Enter your Data : ";
    cin >> data;

    while (data != -1)
    {
        root = InsertData(root, data);
        cin >> data;
    }
}

bool ValidateBST(Node *&root, long long int lb, long long int ub)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data > lb && root->data < ub)
    {
        bool left = ValidateBST(root->left, lb, root->data);
        bool right = ValidateBST(root->right, root->data, lb);
        return left && right;
    }
    return false;
}

bool ValidBST(Node *&root)
{
    long long int lb = -4294967296;
    long long int ub = 4294967296;
    return ValidateBST(root, lb, ub);
}

int main()
{
    Node *root = NULL;
    CreateBST(root);
    cout << "Valid BST :" << ValidBST(root);
    return 0;
}