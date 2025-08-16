
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
    cout << "Enter your node :";

    cin >> data;

    while (data != -1)
    {
        root = InsertData(root, data);
        cin >> data;
    }
}

int KSmallestElement(Node *&root, int &k)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftPart = KSmallestElement(root->left, k);
    if (leftPart != -1)
    {
        return leftPart;
    }
    k--;
    if (k == 0)
    {
        return root->data;
    }
    int rightPart = KSmallestElement(root->right, k);
    return rightPart;
}

int main()
{
    Node *root = NULL;
    CreateBST(root);
    int k = 3;
    cout << "The Kth Smallest Element : " << KSmallestElement(root, k);
    return 0;
}