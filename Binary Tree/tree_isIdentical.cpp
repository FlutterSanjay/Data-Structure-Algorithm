// The Tree is Identical if the structure and values of both trees are the same
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};


Node* buildTree(Node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left : "<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in rigth : "<<endl;
    root->right=buildTree(root->right);
    return root;
}


bool isIdentical(Node* root1, Node* root2){
    // if both trees are empty
    if(root1== NULL && root2== NULL){
        return true;
        
    }

    if((root1!=NULL && root2!=NULL) && (root1->val == root2->val) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right)){
        return true;
}
return false;
}

int main(){
    Node* root1=NULL;
    root1=buildTree(root1);
    Node* root2=NULL;
    root2=buildTree(root2);
    if(isIdentical(root1, root2)){
        cout<<"Both Trees are Identical"<<endl;
    }  else{
        cout<<"Both Trees are not Identical"<<endl;
    }
    return 0;
}
