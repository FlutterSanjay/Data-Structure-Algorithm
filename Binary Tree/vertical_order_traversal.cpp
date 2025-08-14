// Vertical Level Traversal
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

vector<vector<int>> VerticalOrderTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    // requirement
    queue<pair<Node *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> mp;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        Node *&data = temp.first;
        int &row = temp.second.first;
        int &col = temp.second.second;
        mp[col][row].insert(data->data);

        if (data->left)
        {
            q.push({data->left, {row + 1, col - 1}});
        }

        if (data->right)
        {
            q.push({data->right, {row + 1, col + 1}});
        }
    }

    // Store the data in the ans
    for (auto it : mp)
    {
        auto &colMp = it.second;
        vector<int> vLink;
        for (auto i : colMp)
        {
            auto &mSet = i.second;
            vLink.insert(vLink.end(), mSet.begin(), mSet.end());
        }
        ans.push_back(vLink);
    }

    return ans;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
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
    root = CreateTree(root);
    vector<vector<int>> ans = VerticalOrderTraversal(root);
    for (auto it : ans)
        for (auto i : it)
            cout << i << " ";

    // levelOrderTraversal(root);

    return 0;
}