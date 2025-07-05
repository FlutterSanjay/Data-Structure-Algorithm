// Implementation of All Order Traversal
#include<iostream>
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

Node* build_tree(Node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    // left part
    cout<<"Enter the Data of left part : "<<endl;
    root->left=build_tree(root->left);

    // right part
    cout<<"Enter the Data of Right part : "<<endl;
    root->right=build_tree(root->right);
    return root;
}


// ..........Implementation of Inorder Traversal....... (LNR)


void inorder(Node* root){
    // base code
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


// ............Implementation of Preorder Traversal ...............(NLR)


void preorder(Node* root){
    //base code
    if(root==NULL){
        return ;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}



// ..................Implementation of Postorder Traversal..........(LRN)


void postorder(Node* root){
    // base code
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main(){
    Node* root=NULL;
   root= build_tree(root);
    
    // .........InOrder Traversal.........
    inorder(root);
    cout<<endl;
    //.............PreOrder Traversal ..........
    preorder(root);
    cout<<endl;
    // ................PostOrder Traversal ...........

    postorder(root);
    cout<<endl;
    return 0; 

}