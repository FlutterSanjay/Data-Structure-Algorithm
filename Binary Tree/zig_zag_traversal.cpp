// Zig Zag Traversal of Binary Tree
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
        this->val = data;
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

vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    // Requirement
    queue<Node *> q;
    bool LtoR = true;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            int index = LtoR ? i : size - 1 - i;
            temp[index] = front->val;

            if (front->left)
            {
                q.push(front->left);
            }

            if (front->right)
            {
                q.push(front->right);
            }
        }
        LtoR = !LtoR; // Toggle the direction
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    Node *root = NULL;
    root = CreateBinaryTree(root);
    vector<vector<int>> result = zigZagTraversal(root);
    cout << "Zig Zag Traversal: " << endl;
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}