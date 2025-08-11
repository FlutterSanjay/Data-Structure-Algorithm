// Binary Tree Implementation
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;
Node(int d){
  this->data=d;
  left=NULL;
  right=NULL;
}
};

Node* CreateTree(Node* &root){
  int data;
  cout<<"Enter the data :";
  cin>>data;

  if(data == -1){
    return NULL;
  }
  root=new Node(data);

  cout<<"Enter the data for left : "<<root->data<<endl;
 root->left=CreateTree(root->left);
  cout<<"Enter the data for right : "<<root->data<<endl;
root->right = CreateTree(root->right);

  return root;
}


void printLeftBoundary(Node* &root){
  if(root==NULL){
    return;
  }
  if(root->left == NULL && root->right == NULL){
    return;
  }
  cout<<root->data<<" ";

  if(root->left !=NULL){
    printLeftBoundary(root->left);
  }
 else{
    printLeftBoundary(root->right);
 }

}

void printRightBoundary(Node* &root){
  if(root==NULL){
    return;
  }
  if(root->right ==NULL && root->left == NULL){
    return;
  }

 

  if(root->right!=NULL){
    printRightBoundary(root->right);
  }else{
    printRightBoundary(root->left);
  }
   cout<<root->data<<" ";
  
}

void printLeafNodes(Node* &root){
  if(root==NULL){
    return;
  }

  if(root->left ==NULL && root->right == NULL){
    cout<<root->data<<" ";
  }
  printLeafNodes(root->left);
  printLeafNodes(root->right);
}

void printBoundary(Node* &root){
  if(root==NULL){
    return;
  }
  printLeftBoundary(root); // Part A
  printLeafNodes(root); // Part B

  // Part C
  if(root->right != NULL){
      printRightBoundary(root->right);
  }else{
      printRightBoundary(root);
  }
    
}
int main(){
  Node* root=NULL;
  // 20 8 22 4 12 10 14 25
  root=CreateTree(root);
  printBoundary(root);
  cout<<endl;
  return 0;
}