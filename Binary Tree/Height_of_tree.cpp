// Find the height of Tree
#include<iostream>
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

Node* build_tree(Node* root){
    cout<<"Enter the your no :";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    // left part
    cout<<"Enter the data for left part of "<<data<<":"<<endl;
    root->left=build_tree(root->left);
    cout<<"Enter the data for right part of "<<data<<":"<<endl;
    root->right=build_tree(root->right);
    return root;
}

// ....Height code....
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;
    return ans;
}

int main(){
    Node* root=NULL;
    root=build_tree(root);

    int result=height(root);
    cout<<"The Height of Tree : "<<result;
    return 0;
}