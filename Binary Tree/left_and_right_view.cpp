// Binary Tree Inmplementation
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



//leftView in Binary Tree
void LeftView(Node* &root,int lvl,vector<int>& ans){
  if(root==NULL){
    return;
  }

  // condition for left view
  if(lvl == ans.size()){
    ans.push_back(root->data);
    cout<<root->data<<" ";
  }

  LeftView(root->left,lvl+1,ans);
  LeftView(root->right,lvl+1,ans);
}

// Right View in Binary Tree
void RightView(Node* &root,int lvl,vector<int>& ans){
  if(root==NULL){
    return;
  }
  // condition for right view
  if(lvl == ans.size()){
    ans.push_back(root->data);
    cout<<root->data<<" ";
  }

  RightView(root->right,lvl+1,ans);
  RightView(root->left,lvl+1,ans);
}


int main(){
  Node* root=NULL;
  root=CreateTree(root);
  
  cout<<"Left View of Binary Tree"<<endl;
  vector<int>ans;
  LeftView(root,0,ans);
  cout<<endl;
  cout<<"Right View of Binary Tree"<<endl;
  vector<int>ans1;
  RightView(root,0,ans1);
  cout<<endl;
  cout<<"Top View of Binary Tree"<<endl;

  return 0;
}