// Create BST using InOrder Traversal
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

Node *CreateBST(int arr[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    int element = arr[mid];
    Node *temp = new Node(element);

    temp->left = CreateBST(arr, s, mid - 1);
    temp->right = CreateBST(arr, mid + 1, e);
    return temp;
}

void LevelOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    // Requirement
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << front->data << " ";

        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
}

int main()
{
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int s = 0;
    int e = 7;
    Node *root = CreateBST(arr, s, e);
    LevelOrderTraversal(root);
    return 0;
}