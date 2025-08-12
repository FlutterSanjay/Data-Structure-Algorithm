// Fastest way to find the diameter of Tree
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        bool isBalance = true;
        Node(int d){
            this->data = d;
            left = NULL;
            right = NULL;
        }

    bool BalanceTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int LP = BalanceTree(root->left);
    int RP = BalanceTree(root->right);

    if(isBalance && abs(LP-RP)>1){
        isBalance = false;
    }
    return max(LP,RP) +1 ;
}
};

Node* CreateTree(Node* &root){

    int data;
    cout << "Enter Your Value: ";
    cin >> data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    
    cout << "Enter your Left " << root->data << endl;
    root->left = CreateTree(root->left);
        cout << "Enter your Right " << root->data << endl;
    root->right = CreateTree(root->right);

    return root;
}

// Level Order Traversal
void LevelOrderTraversal(Node* &root){
    if(root== NULL){
        return;
    }
    // requirement
    queue<Node *> q;

    // Initialization
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}


int main(){
   Node *root = NULL;
    root = CreateTree(root);
    LevelOrderTraversal(root);

    Node q(0);  // Create a Node object instead of pointer
    q.BalanceTree(root);
    cout << "Balance Tree: " << root->isBalance;  // Access D through root

    return 0;
}