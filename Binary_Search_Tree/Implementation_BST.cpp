// Implementation of Binary Search Tree
#include<iostream>
#include<stdbool.h>
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
void input_take(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root=insert_BST(root,data);
        cin>>data;
    }
}
int min(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

Node* deletion(Node* root,int val){
if(root==NULL){
    return root;
}
if(root->data==val){
    // zero child
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }
    //one child
    if(root->left !=NULL && root->right==NULL){
        Node* temp=root->left;
        delete root;
        return temp;
    }
    if(root->left==NULL && root->right!=NULL){
        Node* temp=root->right;
        delete root;
        return temp;
    }
    // two child
    if(root->left!=NULL && root->right !=NULL){
        int mini=min(root->right);
        root->data=mini;
        root->right=deletion(root->right,val);
        return root;
    }
 }
    else if(root->data >val){
        root->left=deletion(root->left,val);
        return root;
    }
    else{
        root->right=deletion(root->right,val);
        return root;
    }


}




bool sear(Node* root,int x){
    if(root==NULL) return false;
    if(root->data==x){
        return true;
    }
    if(root->data>x){
        return sear(root->left,x);
    }
    else{
        return sear(root->right,x);
    }
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    cout<<"Enter the data to create BST"<<endl;
    // Input data - 4 12 19 13 10 9
    input_take(root);
    Node * temp =deletion(root,4);
    cout<<"**************OUTPUT**************"<<endl;
    cout<<"\n *****Inorder Printing*****\n";
    inorder(temp);
    bool result=sear(temp,12);
    if(result) cout<<"\nData Found !";
    else cout<<"Data Not Found !";
    return 0;
}