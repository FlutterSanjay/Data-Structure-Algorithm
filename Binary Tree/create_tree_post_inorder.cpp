// Create Tree using postOrder and inorder traversal
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
void PutElementToMap(map<int,int>& mp,int in[],int size){
  for(int i=0;i<size;i++){
    int element=in[i];
    int index=i;
    mp[element]=index;
  }
 
}
Node* buildTree(int post[],int in[],int &postIndex,int inStart,int inEnd,int size,map<int,int>& mp){

  // Base Case
  if(inStart>inEnd || postIndex<0){
    return NULL;
  }

  // Create a New Node
  int element=post[postIndex];
  Node* root=new Node(element);
  postIndex--;
  
  


  int position = mp[element];
  root->right=buildTree(post,in,postIndex,position+1,inEnd,size,mp);
  root->left=buildTree(post,in,postIndex,inStart,position-1,size,mp);
  
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
  int post[]={8,6,14,4,10,2};
  int in[]={8,14,6,2,10,4};
  int size=6;
  map<int,int> mp;
  int preIndex=size-1;
  PutElementToMap(mp,in,size);
  Node* root=buildTree(post,in,preIndex,0,size-1,size,mp);
  LevelOrderTravel(root);
  

  return 0;
}