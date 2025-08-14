// Path Sum Three / K-sum Path
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

Node *CreateTree(Node *&root)
{
    int data;
    cout << "Enter the data :";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the data for left : " << root->data << endl;
    root->left = CreateTree(root->left);
    cout << "Enter the data for right : " << root->data << endl;
    root->right = CreateTree(root->right);

    return root;
}

void solve(Node *&root, int targetSum, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (targetSum == root->data)
    {
        ans++;
    }
    solve(root->left, targetSum - root->data, ans);
    solve(root->right, targetSum - root->data, ans);
}
// K-Sum Path
void pathSum(Node *root, int targetSum, int &ans)
{

    if (root != NULL)
    {
        solve(root, targetSum, ans);
        pathSum(root->left, targetSum, ans);
        pathSum(root->right, targetSum, ans);
    }
}

int main()
{
    Node *root = NULL;
    root = CreateTree(root);
    int targetSum = 8;
    int ans = 0;
    pathSum(root, targetSum, ans);
    cout << "Path Sum : " << ans << endl;

    return 0;
}