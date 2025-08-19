// Convert Sorted Linked List into BST
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

// Insert data into BST
Node *InsertData(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
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

// Take input until -1
void CreateNode(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertData(root, data);
        cin >> data;
    }
}

// Convert BST to DLL (inorder, right-to-left)
void ConvertBSTIntoDDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    // Right subtree
    ConvertBSTIntoDDLL(root->right, head);

    // Link current node with head
    root->right = head;
    if (head != NULL)
        head->left = root;

    // Move head to current node
    head = root;

    // Left subtree
    ConvertBSTIntoDDLL(root->left, head);
}

// Count nodes in DLL
int countNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->right;
    }
    return count;
}

// Convert Sorted DLL into Balanced BST
Node *SortedDLLToBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    // Left subtree
    Node *leftSubTree = SortedDLLToBST(head, n - 1 - n / 2);

    // Root node
    Node *root = head;
    root->left = leftSubTree;

    // Move DLL head forward
    head = head->right;

    // Right subtree
    root->right = SortedDLLToBST(head, n / 2);

    return root;
}

// Print Doubly Linked List
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->right != NULL)
            cout << " <-> ";
        temp = temp->right;
    }
    cout << endl;
}

// Level Order Traversal
void LevelOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << front->data << " ";

        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;
    cout << "Enter your Data (-1 to stop):" << endl;
    CreateNode(root);

    Node *head = NULL;
    ConvertBSTIntoDDLL(root, head);

    cout << "Printing the Doubly Linked List:" << endl;
    printLL(head);

    int n = countNodes(head);
    Node *bstRoot = SortedDLLToBST(head, n);

    cout << "Level Order Traversal of Balanced BST:" << endl;
    LevelOrderTraversal(bstRoot);

    return 0;
}
