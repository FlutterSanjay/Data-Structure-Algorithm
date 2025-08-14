// Transform to Sum Tree
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *CreateBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data for inserting in left : ";
    root->left = CreateBinaryTree(root->left);
    cout << "Enter data for inserting in right : ";
    root->right = CreateBinaryTree(root->right);
    return root;
}

int findSumTree(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }

    // Leaf Condition
    if (root->left == NULL && root->right == NULL)
    {
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    int lSum = findSumTree(root->left);
    int rSum = findSumTree(root->right);
    int parentData = root->data;
    root->data = lSum + rSum;
    return root->data + parentData;
}

void SumToTree(Node *root)
{
    findSumTree(root);
}
int main()
{
    Node *root = NULL;

    root = CreateBinaryTree(root);

    SumToTree(root);
    cout << "Sum of Tree :" << root->data;

    return 0;
}