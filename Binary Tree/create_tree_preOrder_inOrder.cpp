// Create Tree using preorder and inorder traversal
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int d){
  this->data=d;
  this->left=NULL;
  this->right=NULL;
}
};

// int search(int in[],int inStart,int inEnd,int size,int element){
//   for(int i=inStart;i<size;i++){
//     if(in[i]==element){
//       return i;
      
//     }
//   }
//   return -1;
// }
int search(map<int,int>& mp,int element,int in[],int size){
  for(int i=0;i<size;i++){
    int element=in[i];
    int index=i;
    mp[element]=index;
  }
  return mp[element];
}
Node* buildTree(int pre[],int in[],int &preIndex,int inStart,int inEnd,int size){

  // Base Case
  if(inStart>inEnd || preIndex>size){
    return NULL;
  }
map<int,int> mp;
  // Create a New Node
  int element=pre[preIndex];
  Node* root=new Node(element);
  preIndex++;
  
  


  int position = search(mp,element,in,size);
  root->left=buildTree(pre,in,preIndex,inStart,position-1,size);
  root->right=buildTree(pre,in,preIndex,position+1,inEnd,size);
  return root;
}


void LevelOrderTravel(Node* &root){
  if(root==NULL){
    return;
  }

  queue<Node*> q;
  // initial Node
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

int main(){
  int pre[]={2,8,10,6,4,12};
  int in[]={10,8,6,2,4,12};
  int size=6;
  int preIndex=0;
  Node* root=buildTree(pre,in,preIndex,0,size-1,size);
  LevelOrderTravel(root);
  

  return 0;
}