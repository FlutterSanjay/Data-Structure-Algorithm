// Searching in Binary Tree
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

bool SearchingBST(Node *&root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data > target)
    {
        return SearchingBST(root->left, target);
    }
    else
    {
        return SearchingBST(root->right, target);
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter your data: ";
    CreateBST(root);

    int target = 25;
    cout << "Seaching of tree : " << SearchingBST(root, target);

    return 0;
}