// Balanced Binary Tree

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        
        int data;
        Node *left;
        Node *right;
        Node(int val){
            this->data = val;
            left = NULL;
            right = NULL;
        }
};

Node* CreateTree(Node* root){
    int data;
    cout<< "Enter the data: ";
    cin >> data;
    if(data==-1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for left of " << data << ": ";
    root->left = CreateTree(root->left);
    cout << "Enter data for right of " << data << ": ";
    root->right = CreateTree(root->right);
    return root;

}

// height of tree
int height(Node* root){
    if(root== NULL){
        return 0;
    }
    int leftPart = height(root->left);
    int rightPart = height(root->right);
    return max(leftPart, rightPart) + 1;
}

// Check if the tree is balanced
bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    // 1 Case solve
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff =abs(leftHeight - rightHeight);
    bool ans = (diff <= 1) ? true : false;

    // Recursion solve
    bool leftPart = isBalanced(root->left);
    bool rightPart = isBalanced(root->right);
    if(ans && leftPart && rightPart){
        return true;
    }else{
        return false;
    }
}

int main(){

    Node* root = NULL;
    root = CreateTree(root);
    if(isBalanced(root)){
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    // Clean up memory
    delete root; // Note: This is a simple delete, for a complete tree, you would need to delete all nodes.
    return 0;
}