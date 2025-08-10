// Sum of the Longest Bloodline of Binary Tree
// or // Longest Path Sum in Binary Tree

// Sum of the Longest BloodLine of Binary Tree
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

void CreateTree(Node* &root){
  int data;
  cout<<"Enter the data: ";
  cin>>data;
  if(data == -1){
    return ;
  }
  root =new Node(data);
  cout<<"Enter the data for left of "<<root->data<<endl;
  CreateTree(root->left);
  cout<<"Enter the data for right of "<<root->data<<endl;
    CreateTree(root->right);
}

int maxLen=0;
void LongestBloodLine(Node* root,int& sum,int& len,int &maxi){
  
  
  if(root==NULL){
    return;
  }

  // leaf Node
  if(root->left == NULL && root->right == NULL){
 
    sum+=root->data;
    len++;
    if(len>maxLen){
      maxLen=len;
      maxi=sum;
    }
    else if(len==maxLen){
      maxi=max(maxi,sum);
    }
    sum-=root->data;
    len--;
    return;

   


   
  }
  // other Node
  sum+=root->data;
  len++;


 
  
  

  LongestBloodLine(root->left,sum,len,maxi);
  LongestBloodLine(root->right,sum,len,maxi);

  sum-=root->data;
  len--;
}
int main(){
  Node* root=NULL;
  CreateTree(root);
  int maxi=INT_MAX;
  int sum=0;
  int len=0;
  LongestBloodLine(root,sum,len,maxi);
  cout<<"Sum of the Longest BloodLine of Binary Tree is: "<<maxi<<endl;

 
  
  return 0;
}