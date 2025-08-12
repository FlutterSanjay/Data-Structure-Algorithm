// Diagonal Traversal of a Binary Tree
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

vector<int> diagonalTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while (temp != NULL)
        {
            ans.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int> result = diagonalTraversal(root);
    cout << "Diagonal Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
