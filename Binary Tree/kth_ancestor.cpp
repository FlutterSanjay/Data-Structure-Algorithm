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

bool KAncestor(Node* &root,int& p,int& k){
  if(root==NULL){
    return false;
  }

  // check for p and q
  if(root->data==p){
    return true;
  }

bool leftPart=KAncestor(root->left,p,k);
  // rightPart
bool rightPart=KAncestor(root->right,p,k);
  

  if(leftPart==true || rightPart==true){
    k--;
  }
  if(k==0){
    cout<<"Kth Ancestor is :"<<root->data<<endl;
    k=-1;
  }
  
 return leftPart || rightPart;

}
int main(){

  Node* root=NULL;
  root=CreateTree(root);
  int p=120;
  int k = 2;
  KAncestor(root, p, k);
  

  return 0;
}