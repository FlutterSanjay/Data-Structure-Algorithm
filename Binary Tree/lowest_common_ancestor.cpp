// implement Tree
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
  cout<<"Enter Your Value :";
  cin>>data;
  if(data==-1){
    return NULL;
  }
  Node* newNode=new Node(data);
  cout<<"Enter Left child of "<<newNode->data<<endl;
    newNode->left=CreateTree(newNode->left);

  cout<<"Enter Rigth Child of "<<newNode->data<<endl;
    newNode->right=CreateTree(newNode->right);
  return newNode;
}

Node* LowestCommonAncestor(Node* &root,Node* p,Node* q){
  if(root==NULL){
    return NULL;
  }

  // check for p and q
  if(root->data==p->data){
    return p;
  }
  if(root->data==q->data){
    return q;
  }
  // leftPart
  Node* leftPart=LowestCommonAncestor(root->left,p,q);
  // rightPart
  Node* rightPart=LowestCommonAncestor(root->right,p,q);

  if(leftPart==NULL && rightPart==NULL){
    return NULL;
  }
  else if(leftPart !=NULL && rightPart==NULL){
    return leftPart;
  }else if(leftPart !=NULL && rightPart ==NULL){
    return rightPart;
  }else{
    return root;
  }
}
int main(){
  Node* root=NULL;
  root=CreateTree(root);
  // LevelOrderTraversal(root);
  Node* p=new Node(60);
  Node* q=new Node(40);
  Node* ans=LowestCommonAncestor(root,p,q);
  cout<<"Lowest Common Ancestor is :"<<ans->data<<endl;

  return 0;
}