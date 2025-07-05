// Find the Diameter of Tree
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
    cout<<"Enter your no : ";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    //left part
    cout<<"Enter the Data for Left part "<<data<<":"<<endl;
    root->left=build_tree(root->left);

    // right part
    cout<<"Enter the data for Right part "<<data<<":"<<endl;
    root->right=build_tree(root->right);

    return root;
}

// Find Height code

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;

    return ans;
}

// Find Diameter
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int combo=height(root->left)+1+height(root->right);

    int result=max(op1,max(op2,combo));
    return result;
}
int main(){
    Node* root=NULL;
    root=build_tree(root);
    int result=diameter(root);
    cout<<"Diametre of Tree : "<<result;
    return 0;
}
