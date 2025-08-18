// Two Sum IV - Input is a BST
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

void InorderTraversal(Node *&root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left, arr);
    arr.push_back(root->data);
    InorderTraversal(root->right, arr);
}
bool findSum(vector<int> &arr, int &target)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

bool TwoSum(Node *&root, int &target)
{
    if (root == NULL)
        return false;
    vector<int> arr;
    InorderTraversal(root, arr);
    return findSum(arr, target);
}

int main()
{
    Node *root = NULL;
    cout << "Enter your Value: ";
    CreateBST(root);
    int target = 300;
    cout << "Two Sum : " << TwoSum(root, target);
    return 0;
}