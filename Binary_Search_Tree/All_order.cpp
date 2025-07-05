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

// preorder
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//postorder
void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Output
void level(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter the BST data : "<<endl;
    take_input(root);
    cout<<"*********************OUTPUT**********************"<<endl;
    level(root);
    cout<<endl;
    cout<<"************Printing Inorder**********"<<endl;
    inorder(root);
     cout<<endl;
    cout<<"*******************Printing Preorder***************"<<endl;
    preorder(root);
     cout<<endl;
    cout<<"*************Printing PostOrder*****************"<<endl;
    postorder(root);
    return 0;

}