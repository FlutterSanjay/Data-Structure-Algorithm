// Convert the BST into Doubly Linked List
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

// Convert BST to DLL
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

int main()
{
    Node *root = NULL;
    cout << "Enter your Data (-1 to stop):" << endl;
    CreateNode(root);

    Node *head = NULL;
    ConvertBSTIntoDDLL(root, head);

    cout << "Printing the Doubly Linked List:" << endl;
    printLL(head);

    return 0;
}
