// Convert BST into Min Heap
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
Node *insertData(Node *&root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insertData(root->left, data);
    }
    else
    {
        root->right = insertData(root->right, data);
    }
    return root;
}
void CreateBST(Node *&root)
{
    int data;
    cout << "Enter your Node Value :" << endl;
    cin >> data;
    while (data != -1)
    {
        root = insertData(root, data);
        cin >> data;
    }
}

void inorder(Node *&root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

Node *preOrder(Node *&root, vector<int> &ans, int &index)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->data = ans[index++];
    preOrder(root->left, ans, index);
    preOrder(root->right, ans, index);
    return root;
}

void LevelOrderTravel(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    // initial Node
    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    CreateBST(root);
    vector<int> result;
    inorder(root, result);
    int i = 0;
    root = preOrder(root, result, i);

    LevelOrderTravel(root);

    return 0;
}