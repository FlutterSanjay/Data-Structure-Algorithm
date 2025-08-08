// Convert a Binary Tree to a Sum Tree
// where each node contains the sum of its left and right subtrees
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


void LevelOrderTraversal(Node* &root){
  if(root==NULL){
    return;
  }
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left){
      q.push(temp->left);
    }

    if(temp->right){
      q.push(temp->right);
    }
  }
}

int sumTree(Node* &root){
  if(root==NULL){
    return 0;
  }
 
  int leftPart=sumTree(root->left);
  int rightPart=sumTree(root->right);
  root->data+=leftPart+rightPart;

  return root->data;

}
int main(){
  Node* root=NULL;
  root=CreateTree(root);
  // LevelOrderTraversal(root);
  cout<<endl;
  sumTree(root);
  LevelOrderTraversal(root);


  return 0;
}