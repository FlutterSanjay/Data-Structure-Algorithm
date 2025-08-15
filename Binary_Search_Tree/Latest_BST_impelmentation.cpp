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
// PreOrder

void PreOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    cout << "Enter your data: ";
    CreateBST(root);
    cout << "Level Order Traversal ........" << endl;
    LevelOrderTraversal(root);
    cout << endl;
    cout << "PreOrder Traversal ....." << endl;
    PreOrder(root);
    cout << endl;
    cout << "InOrder Traversal ....." << endl;
    InOrder(root);
    cout << endl;
    cout << "PostOrder Traversal ....." << endl;
    PostOrder(root);
    return 0;
}