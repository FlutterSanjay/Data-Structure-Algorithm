// Delete Node in a BST

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

int MaxVal(Node *&root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node *deleteNodeBST(Node *&root, int target)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == target)
    {
        // 4 Cases
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            return temp;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            return temp;
        }

        else
        {

            int inorderPre = MaxVal(root->left);
            root->data = inorderPre;
            root->left = deleteNodeBST(root->left, inorderPre);
            return root;
        }
    }
    else if (root->data > target)
    {
        root->left = deleteNodeBST(root->left, target);
    }
    else
    {
        root->right = deleteNodeBST(root->right, target);
    }
    return root;
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
    Node *root = NULL;
    cout << "Enter your data: ";
    CreateBST(root);
    cout << "Enter the target: ";
    int target;
    cin >> target;
    deleteNodeBST(root, target);
    cout << "After Deletion: ";
    LevelOrderTraversal(root);

    return 0;
}