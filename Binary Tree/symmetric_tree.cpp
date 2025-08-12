// Binary Tree Symmetric Check
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left : " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in rigth : " << endl;
    root->right = buildTree(root->right);
    return root;
}

bool IsIdentical(Node *p, Node *q)
{

    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p != NULL && q != NULL)
    {
        if ((p->val == q->val) && IsIdentical(p->left, q->right) && IsIdentical(p->right, q->left))
        {
            return true;
        }
    }
    return false;
}

bool IsMirror(Node *root)
{
    return IsIdentical(root->left, root->right);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    if (IsMirror(root))
    {
        cout << "The Binary Tree is Symmetric" << endl;
    }
    else
    {
        cout << "The Binary Tree is not Symmetric" << endl;
    }
    return 0;
}