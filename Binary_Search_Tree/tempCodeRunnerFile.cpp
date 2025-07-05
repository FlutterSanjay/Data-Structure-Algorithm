// Implementing 1->Preorder,2->PostOrder,3->Inorder
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insert_BST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data > root->data){
        root->right=insert_BST(root->right,data);
    }
    else{
        root->left=insert_BST(root->left,data);
    }
    return root;
}

void take_input(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root=insert_BST(root,data);
        cin>>data;
    }
}

// inorder
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
