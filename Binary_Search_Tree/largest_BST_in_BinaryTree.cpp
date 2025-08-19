// Find the Largest BST in Binary Tree
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
class NodeData
{
public:
    int size;
    int maxVal;
    int minVal;
    bool validBST;
    NodeData() {}

    NodeData(int d, int max, int min, bool valid)
    {
        this->size = d;
        maxVal = max;
        minVal = min;
        validBST = valid;
    }
};

NodeData findLargestBST(Node *root, int &ans)
{
    if (root == NULL)
    {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left, ans);
    NodeData rightAns = findLargestBST(root->right, ans);

    // checking Start here
    NodeData currNodeAns;
    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.maxVal = max(root->data, rightAns.maxVal);
    currNodeAns.minVal = min(root->data, leftAns.minVal);

    if (leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal))
    {
        currNodeAns.validBST = true;
    }
    else
    {
        currNodeAns.validBST = false;
    }
    if (currNodeAns.validBST)
    {
        ans = max(ans, currNodeAns.size);
    }
    return currNodeAns;
}

int main()
{
    Node *root = new Node(50);
    Node *first = new Node(30);
    Node *second = new Node(60);
    Node *third = new Node(5);
    Node *four = new Node(20);
    Node *five = new Node(45);
    Node *sixth = new Node(70);
    Node *seven = new Node(65);
    Node *eight = new Node(80);

    root->left = first;
    root->right = second;

    first->left = third;
    first->right = four;

    second->left = five;
    second->right = sixth;

    sixth->left = seven;
    sixth->right = eight;

    int ans = 0;
    findLargestBST(root, ans);
    cout << "Largest BST in Binary Tree : " << ans;
    return 0;
}